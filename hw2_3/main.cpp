#include "MatrixType.h"
#include <ctime>
#include <vector>

using namespace std;

enum class menu
{
	GetNewMatrix = 1,
	AddMatrices,
	SubMatrices,
	MultiplyMatrices,
	PrintMatrix,
	Quit
};

void runMenu(vector<MatrixType>& vec_mat, menu& select_menu);

void main()
{
	vector<MatrixType> my_met;
	menu select;

	do
	{
		try
		{
			runMenu(my_met, select);
		}
		catch (string message)
		{
			cout << message << endl;
		}
	}
	while (select != menu::Quit);

}


void runMenu(vector<MatrixType>& vec_mat, menu& select_menu)
{
	cout << "�޴��� �ϳ� ����ּ���" << endl;
	cout << "1. GetNewMatrix " << endl;
	cout << "2. AddMatrices " << endl;
	cout << "3. SubMatrices " << endl;
	cout << "4. MultiplyMatrices " << endl;
	cout << "5. PrintMatrix " << endl;
	cout << "6. Quit " << endl;

	int select_num;					//enum Ŭ������ ���ڸ� ���� ������ ���� int�� �ް� Ÿ��ĳ������ ���ش�.
	cin >> select_num;
	select_menu = (menu)select_num;
	cout << endl;

	switch (select_menu)
	{
	case menu::GetNewMatrix:
	{
		MatrixType matrix;  //��Ʈ���� �ϳ� �����
		int row;
		int col;
		srand((int)time(NULL));
		cout << "row �� ���� �Է����ּ���";
		cin >> row;
		cout << "col �� ���� �Է����ּ���";
		cin >> col;
		matrix.SetSize(row, col); //���� row, col�� ���缭 ��Ʈ���� �������
		for (int i = 0;i < row;i++)
			for (int j = 0;j < col;j++)
				matrix.StoreItem(rand() % 10, i, j); //0~9������ ������ ���� ������
		vec_mat.push_back(matrix); //���Ϳ� ��Ʈ������ �־���
		break;
	}
	case menu::AddMatrices:
	{
		if (vec_mat.size() < 2)
			cout << "��Ʈ���� ���� 2������ ���� ����� �Ұ����մϴ�" << endl;
		else
		{
			int mat_idx1, mat_idx2;
			cout << "�� �� ��Ʈ������ ��ġ�� �Է����ּ���(���� ���� ��Ʈ���� idx: 0 ~ " <<vec_mat.size()-1<<endl;
			cin >> mat_idx1 >> mat_idx2;

			if (mat_idx1<0 || mat_idx2<0 || mat_idx1 > vec_mat.size() - 1 || mat_idx2 > vec_mat.size() - 1) //<vector> asd.size() �� ��ȯ���� unsigned int�̴�.
				//���߿��ҋ��� ������ ������ ������ �� size()�� ��Ʈ�� �ѹ� �ް� �񱳸� ��������!
				cout << "������� ��Ʈ������ ��ġ�� ������ϴ�" << endl;
			else
			{
				MatrixType result;
				vec_mat[mat_idx1].Add(vec_mat[mat_idx2], result);
				vec_mat.push_back(result);
				cout << "���� ���������ϴ�" << endl;
			}
		}
		break;
	}
	case menu::SubMatrices:
	{
		if (vec_mat.size() < 2)
			cout << "��Ʈ���� ���� 2������ ���� ����� �Ұ����մϴ�" << endl;
		else
		{
			int mat_idx1, mat_idx2;
			cout << "���⸦ ������ ��Ʈ������ ��ġ�� �Է����ּ���(���� ���� ��Ʈ���� idx: 0 ~ " << vec_mat.size() - 1 << endl;
			cin >> mat_idx1 >> mat_idx2;

			if (mat_idx1<0 || mat_idx2<0 || mat_idx1 > vec_mat.size() - 1 || mat_idx2 > vec_mat.size() - 1)
				cout << "������� ��Ʈ������ ��ġ�� ������ϴ�" << endl;
			else
			{
				MatrixType result;
				vec_mat[mat_idx1].Sub(vec_mat[mat_idx2], result);
				vec_mat.push_back(result);
				cout << "���� �������ϴ�" << endl;
			}
		}
		break;
	}

	case menu::MultiplyMatrices:
	{
		if (vec_mat.size() < 2)
			cout << "��Ʈ���� ���� 2������ ���� ����� �Ұ����մϴ�" << endl;
		else
		{
			int mat_idx1, mat_idx2;
			cout << "���� ��Ʈ������ ��ġ�� �Է����ּ���(���� ���� ��Ʈ���� idx: 0 ~ " << vec_mat.size() - 1 << endl;
			cin >> mat_idx1 >> mat_idx2;

			if (mat_idx1<0 || mat_idx2<0 || mat_idx1 > vec_mat.size() - 1 || mat_idx2 > vec_mat.size() - 1)
				cout << "������� ��Ʈ������ ��ġ�� ������ϴ�" << endl;
			else
			{
				MatrixType result;
				vec_mat[mat_idx1].Mult(vec_mat[mat_idx2], result);
				vec_mat.push_back(result);
				cout << "���� ���������ϴ�." << endl;
			}
		}
		break;
	}

	case menu::PrintMatrix:
	{
		if (vec_mat.size() == 0)
			cout << "���� ������ ��Ʈ������ �����ϴ�" << endl;
		else
		{
			ofstream outfile;
			int mat_idx;
			cout<<"���� ������ ��Ʈ������ ��ȣ�� �Է����ּ���(���� ���� ��Ʈ���� idx: 0 ~ " << vec_mat.size() - 1 << endl;
			cin >> mat_idx;

			if (mat_idx > vec_mat.size() - 1)
				cout << "������� ��Ʈ������ ��ġ�� ������ϴ�" << endl;
			else
			{
				vec_mat[mat_idx].Print(outfile);
				cout << mat_idx << " ��° �迭�� ����Ǿ����ϴ�." << endl;
			}
		}
		break;
	}
	case menu::Quit:
	{
		cout << "���α׷��� �����մϴ�" << endl;
		break;
	}

	default:
	{	
		cout << "�޴��� ������ ������ϴ� �ٽ����ּ���" << endl;
		break;
	}
	}
}