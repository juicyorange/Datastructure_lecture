#include "SquareMatrix.h"

SquareMatrix::SquareMatrix() :n(0)
{
	std::cout << "�����Ϸ�" << std::endl;
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
		std::cout << "�����Ϸ�" << std::endl;
	}
	else
	{
		std::cout << "�������� �Ѿ����ϴ�. �⺻���� 0X0��ķ� �ʱ�ȭ(������)" << std::endl;  //������ �ѱ�� �޽��� ���
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
		std::cout << num<<"��� ������ 0���� �ʱ�ȭ �Ϸ�" << std::endl;
	}
	else
	{
		std::cout << "�������� �Ѿ����ϴ�. " << std::endl;  //������ �ѱ�� �޽��� ���
	}
}


void SquareMatrix::StoreValue(int i, int j, int value)
{
	if (i > n || j > n)  //�� �� �ϳ��� ����� �ִ�ũ��� ������ n���� ũ�� �ȵ�. 
	{
		std::cout << "����� �ִ�ũ��� ������ ���� �Ѿ����ϴ�. " << std::endl;
	}
	else if (i < 0 || j < 0)  //�� �� �ϳ��� 0���� �������� ���� �ȵ�.
	{
		std::cout << "��, �� ���� 0���� �������� ���� �����ϴ�. " << std::endl;
	}
	else
	{
		std::cout << "���� �־����ϴ�." << std::endl;
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
		std::cout << "�� ��Ʈ������ ũ�Ⱑ �ٸ��ϴ�." << std::endl;  // ��Ʈ������ ũ�Ⱑ ���� �ٸ���� ���� �Ұ��� , �޽��� ���
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
		std::cout << "�� ��Ʈ������ ũ�Ⱑ �ٸ��ϴ�." << std::endl; // ��Ʈ������ ũ�Ⱑ ���� �ٸ���� ���� �Ұ��� , �޽��� ���
}

void SquareMatrix::Copy(SquareMatrix& A1) //A2�� ������ ���� ���� �� ����� ũ�Ⱑ �ٸ� 
//��Ʈ������ �־ �׳� �迭ũ�⸦ ���缭 ������ �����ϰ���. ��Ʈ������ ũ����� �����Ѵٰ� ������.
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