#include "MatrixType.h"
MatrixType::MatrixType()
{
	numRows = 0;
	numCols = 0;	//ó�� �ʱ�ȭ�̹Ƿ� 2���� 0���� ���ش�.
}

void MatrixType::MakeEmpty()
{
	/*
	precon
	-��Ʈ������ �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	postcon
	-��Ʈ������ ��� ���� 0�� �Ǿ��־�� �Ѵ�.
	*/
	for (int i = 0; i < numRows;i++)
		for (int j = 0; j < numCols;j++)
			values[i][j] = 0;
}

void MatrixType::SetSize(int rowsSize, int colSize)
{
	/*
	precon
	-rowsSize�� colSize�� 10���� ũ�� �ȵȴ�. 0���� �۾Ƶ� �ȵȴ�
	postcon
	rowsSize�� colSize�� numRows�� numCols�� ����ȴ�
	*/
	if (rowsSize >= 0 && rowsSize < MAX_ROWS && colSize >= 0 && colSize < MAX_ROWS)
	{
		numRows = rowsSize;
		numCols = colSize;
	}
	else
		throw string("����� �ִ� �ִ������ ���"); // ��������� throw����
}

void MatrixType::StoreItem(int item, int row, int col)
{
	/*
	precon
	-�������� �����Ҷ� ���� ������ �迭�� ũ�⺸�� ũ�� �ȵȴ�.
	postcon
	-�Է¹��� �࿭�� item�� ����ִ´�.
	*/
	if (row >= 0 && row < numRows && col >= 0 && col < numCols)
	{
		values[row][col] = item;
	}
	else
		throw string("���� �迭�� �ִ������ ���");
}

void MatrixType::Add(MatrixType&  otherOperand, MatrixType& result)
{
	/*
	precon 
	-������ �� ��Ʈ���� 2���� ������ �� �־����.
	postcon
	-AddSubcompatible�� true�̸� ������ ������ 2���� ��Ʈ������ �ƹ��ų����� result�� ��� ���� �־��ش�
	���� ���� ���ؼ� �־��ش�.
	-AddSubcompatible�� false�̸� ����� ���������ʰ� throw�� ������ �����ش�.
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
		throw string("���ϱ⸦ ������ �迭���� ũ�Ⱑ �ٸ��ϴ�");
}

void MatrixType::Sub(MatrixType&  otherOperand, MatrixType& result)
{
	/*
	precon 
	-������ �� ��Ʈ���� 2���� ������ �� �־����.
	postcon
	-AddSubcompatible�� true�̸� ������ ������ 2���� ��Ʈ������ �ƹ��ų����� result�� ��� ���� �־��ش�
	���� ���� ���ؼ� �־��ش�.
	-AddSubcompatible�� false�̸� ����� ���������ʰ� throw�� ������ �����ش�.
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
		throw string("���⸦ ������ �迭���� ũ�Ⱑ �ٸ��ϴ�");
}

void MatrixType::Mult(MatrixType&  otherOperand, MatrixType& result)
{
	/*
	precon 
	-������ �� ��Ʈ���� 2���� ������ �� �־����. ���� result�� ���� �ʱ�ȭ���־���� 
	0����(+=�� ����ϱ� ������ �����Ⱚ�� ��������� ������ ����������)
	postcon
	MultCompatible�� true�ϋ� ��� ����
	ù��° ��Ʈ������ ����ũ��, �ι��� ��Ʈ������ ���� ũ�⸦ result�� ũ��� �־��ش�.
	���� ������� ���� result�� �־��ش�.
	*/

	if (this->MultCompatible(otherOperand))
	{
		int row = this->numRows;
		int col = otherOperand.numCols;
		result.SetSize(row, col);
		result.MakeEmpty(); // ��İ��� ����Ϸ��� 0���� �ʱ�ȭ ���־����.
		for (int i = 0;i < row;i++)
			for (int j = 0; j < col;j++)
				for (int z = 0; z < this->numCols;z++)
					result.values[i][j] += this->values[i][z] * otherOperand.values[z][j];
	}
	else
		throw string("���ϱ⸦ ������ �迭���� ������ �����ʽ��ϴ�");
}

void MatrixType::Print(ofstream& outfile)
{
	/*
	precon 
	-������ �����ִ�. ��Ʈ������ �ʱ�ȭ���־���Ѵ�.
	postcon
	-���� DataOut.txt �� ���� ���־�� �Ѵ�.
	*/
	outfile.open("DataOut.txt",ios::app);   //ios::app ���������� ������ �ű⿡ �̾ ��
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
		throw string("������ ����� ������ �ʾҽ��ϴ�");
}

bool MatrixType::AddSubCompatible(MatrixType&  otherOperand)
{
	/*
	precon
	- ��Ʈ���� 2���� ��� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	postcon
	- �� ��Ʈ������ ��� ���� ��� ������ true ���� �ϳ��� �ٸ��� false�� ��ȯ
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
	- ��Ʈ���� 2���� ��� �ʱ�ȭ �Ǿ��־�� �Ѵ�
	postcon
	- ù���� ��Ʈ������ col�� �ι��� ��Ʈ������ row�� ���ƾ���
	*/
	if (this->numCols==otherOperand.numRows)
		return true;
	else
		return false;
}