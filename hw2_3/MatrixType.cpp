#include "MatrixType.h"
MatrixType::MatrixType()
{
	numRows = 0;
	numCols = 0;	//처음 초기화이므로 2개다 0으로 해준다.
}

void MatrixType::MakeEmpty()
{
	/*
	precon
	-매트릭스가 초기화 되어있어야 한다.
	postcon
	-매트릭스의 모든 값이 0이 되어있어야 한다.
	*/
	for (int i = 0; i < numRows;i++)
		for (int j = 0; j < numCols;j++)
			values[i][j] = 0;
}

void MatrixType::SetSize(int rowsSize, int colSize)
{
	/*
	precon
	-rowsSize와 colSize가 10보다 크면 안된다. 0보다 작아도 안된다
	postcon
	rowsSize와 colSize가 numRows와 numCols에 저장된다
	*/
	if (rowsSize >= 0 && rowsSize < MAX_ROWS && colSize >= 0 && colSize < MAX_ROWS)
	{
		numRows = rowsSize;
		numCols = colSize;
	}
	else
		throw string("만들수 있는 최대범위를 벗어남"); // 범위벗어난거 throw해줌
}

void MatrixType::StoreItem(int item, int row, int col)
{
	/*
	precon
	-아이템을 저장할때 내가 지정한 배열의 크기보다 크면 안된다.
	postcon
	-입력받은 행열에 item을 집어넣는다.
	*/
	if (row >= 0 && row < numRows && col >= 0 && col < numCols)
	{
		values[row][col] = item;
	}
	else
		throw string("현재 배열의 최대범위를 벗어남");
}

void MatrixType::Add(MatrixType&  otherOperand, MatrixType& result)
{
	/*
	precon 
	-연산을 할 매트릭스 2개가 값들이 들어가 있어야함.
	postcon
	-AddSubcompatible이 true이면 연산을 진행할 2개의 매트릭스중 아무거나에서 result에 행과 열을 넣어준다
	이후 값을 더해서 넣어준다.
	-AddSubcompatible이 false이면 계산을 진행하지않고 throw로 오류를 던저준다.
	*/
	if (this->AddSubCompatible(otherOperand))
	{
		int row = otherOperand.numRows;
		int col = otherOperand.numCols;
		result.SetSize(row, col);
		for (int i = 0; i < row;i++)
			for (int j = 0;j < col;j++)
				result.values[i][j] = this->values[i][j] + otherOperand.values[i][j];
	}
	else
		throw string("더하기를 진행할 배열들의 크기가 다릅니다");
}

void MatrixType::Sub(MatrixType&  otherOperand, MatrixType& result)
{
	/*
	precon 
	-연산을 할 매트릭스 2개가 값들이 들어가 있어야함.
	postcon
	-AddSubcompatible이 true이면 연산을 진행할 2개의 매트릭스중 아무거나에서 result에 행과 열을 넣어준다
	이후 값을 더해서 넣어준다.
	-AddSubcompatible이 false이면 계산을 진행하지않고 throw로 오류를 던저준다.
	*/
	if (this->AddSubCompatible(otherOperand))
	{
		int row = otherOperand.numRows;
		int col = otherOperand.numCols;
		result.SetSize(row, col);
		for (int i = 0; i < row;i++)
			for (int j = 0;j < col;j++)
				result.values[i][j] = this->values[i][j] - otherOperand.values[i][j];
	}
	else
		throw string("빼기를 진행할 배열들의 크기가 다릅니다");
}

void MatrixType::Mult(MatrixType&  otherOperand, MatrixType& result)
{
	/*
	precon 
	-연산을 할 매트릭스 2개가 값들이 들어가 있어야함. 또한 result에 값이 초기화되있어야함 
	0으로(+=을 사용하기 때문에 쓰래기값이 들어있으면 오류가 날수도있음)
	postcon
	MultCompatible이 true일떄 계산 진행
	첫번째 매트릭스의 행의크기, 두번쨰 매트린스의 열의 크기를 result의 크기로 넣어준다.
	이후 두행렬의 곱을 result에 넣어준다.
	*/

	if (this->MultCompatible(otherOperand))
	{
		int row = this->numRows;
		int col = otherOperand.numCols;
		result.SetSize(row, col);
		result.MakeEmpty(); // 행렬곱을 계산하려면 0으로 초기화 되있어야함.
		for (int i = 0;i < row;i++)
			for (int j = 0; j < col;j++)
				for (int z = 0; z < this->numCols;z++)
					result.values[i][j] += this->values[i][z] * otherOperand.values[z][j];
	}
	else
		throw string("곱하기를 진행할 배열들의 조건이 맞지않습니다");
}

void MatrixType::Print(ofstream& outfile)
{
	/*
	precon 
	-파일이 열려있다. 매트릭스가 초기화되있어야한다.
	postcon
	-파일 DataOut.txt 에 값이 들어가있어야 한다.
	*/
	outfile.open("DataOut.txt",ios::app);   //ios::app 기존파일이 있으면 거기에 이어서 씀
	if (outfile.is_open())
	{
		for (int i = 0; i < numRows;i++)
		{
			for (int j = 0; j < numCols;j++)
				outfile << this->values[i][j] << " ";
			outfile << '\n';
		}
		outfile << '\n';
		outfile.close();
	}
	else
		throw string("파일이 제대로 열리지 않았습니다");
}

bool MatrixType::AddSubCompatible(MatrixType&  otherOperand)
{
	/*
	precon
	- 매트릭스 2개가 모두 초기화 되어있어야 한다
	postcon
	- 두 매트릭스의 행과 열이 모두 같으면 true 둘중 하나라도 다르면 false를 반환
	*/
	if (this->numRows == otherOperand.numRows && this->numCols == otherOperand.numCols)
		return true;
	else
		return false;
}

bool MatrixType::MultCompatible(MatrixType&  otherOperand)
{
	/*
	precon
	- 매트릭스 2개가 모두 초기화 되어있어야 한다
	postcon
	- 첫번쨰 매트릭스의 col과 두번쨰 매트릭스의 row가 같아야함
	*/
	if (this->numCols==otherOperand.numRows)
		return true;
	else
		return false;
}