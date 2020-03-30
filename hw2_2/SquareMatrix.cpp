#include "SquareMatrix.h"

SquareMatrix::SquareMatrix() :n(0)
{
	std::cout << "설정완료" << std::endl;
}
SquareMatrix::SquareMatrix(int num) 
{
	if (0 < num && num <= MAX_ROWS)
	{
		n = num-1;
		for (int i = 0;i < num;i++)
			for (int j = 0;j < num;j++)
			{
				Mat[i][j] = 0;
			}
		std::cout << "설정완료" << std::endl;
	}
	else
	{
		std::cout << "범위값을 넘었습니다. 기본값인 0X0행렬로 초기화(생성자)" << std::endl;  //범위를 넘기면 메시지 출력
		n = 0;
	}
}
void SquareMatrix::MakeEmpty(int num)
{
	if (0 <= num && num <= n)
	{
		for (int i = 0;i < num+1;i++)
			for (int j = 0;j < num+1;j++)
			{
				Mat[i][j] = 0;
			}
		std::cout << num<<"행과 열까지 0으로 초기화 완료" << std::endl;
	}
	else
	{
		std::cout << "범위값을 넘었습니다. " << std::endl;  //범위를 넘기면 메시지 출력
	}
}


void SquareMatrix::StoreValue(int i, int j, int value)
{
	if (i > n || j > n)  //둘 중 하나가 행렬의 최대크기로 설정한 n보다 크면 안됨. 
	{
		std::cout << "행렬의 최대크기로 설정한 값을 넘었습니다. " << std::endl;
	}
	else if (i < 0 || j < 0)  //둘 중 하나가 0보다 작은값이 들어가면 안됨.
	{
		std::cout << "행, 열 값중 0보다 작은수는 들어갈수 없습니다. " << std::endl;
	}
	else
	{
		std::cout << "값을 넣었습니다." << std::endl;
		Mat[i][j] = value;
	}
}

void SquareMatrix::Add(SquareMatrix& A1, SquareMatrix& A2) 
{
	if (A1.n == A2.n)
	{
		for (int i = 0;i < A1.n+1;i++)
			for (int j = 0;j < A1.n+1;j++)
			{
				Mat[i][j] = A1.Mat[i][j] + A2.Mat[i][j];
			}
		n = A1.n;
	}
	else
		std::cout << "두 매트릭스의 크기가 다릅니다." << std::endl;  // 매트릭스의 크기가 서로 다른경우 연산 불가능 , 메시지 출력
}

void SquareMatrix::Sub(SquareMatrix& A1, SquareMatrix& A2) 
{
	if (A1.n == A2.n)
	{
		for (int i = 0;i < A1.n+1;i++)
			for (int j = 0;j < A1.n+1;j++)
			{
				Mat[i][j] = A1.Mat[i][j] - A2.Mat[i][j];
			}

		n = A1.n;
	}
	else
		std::cout << "두 매트릭스의 크기가 다릅니다." << std::endl; // 매트릭스의 크기가 서로 다른경우 연산 불가능 , 메시지 출력
}

void SquareMatrix::Copy(SquareMatrix& A1) //A2는 복사한 값을 담을 것 복사는 크기가 다른 
//매트릭스를 넣어도 그냥 배열크기를 맞춰서 내용을 복사하게함. 매트릭스의 크기까지 복사한다고 생각함.
{
	n = A1.n;
	for (int i = 0;i < A1.n+1;i++)
		for (int j = 0;j < A1.n+1;j++)
		{
			Mat[i][j] = A1.Mat[i][j];
		}
}

void SquareMatrix::Printall()
{
	for (int i = 0;i < n+1;i++)
	{
		for (int j = 0;j < n+1;j++)
		{
			std::cout << Mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}