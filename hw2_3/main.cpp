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
	cout << "메뉴를 하나 골라주세요" << endl;
	cout << "1. GetNewMatrix " << endl;
	cout << "2. AddMatrices " << endl;
	cout << "3. SubMatrices " << endl;
	cout << "4. MultiplyMatrices " << endl;
	cout << "5. PrintMatrix " << endl;
	cout << "6. Quit " << endl;

	int select_num;					//enum 클래스가 숫자를 직접 받을수 없어 int로 받고 타입캐스팅을 해준다.
	cin >> select_num;
	select_menu = (menu)select_num;
	cout << endl;

	switch (select_menu)
	{
	case menu::GetNewMatrix:
	{
		MatrixType matrix;  //메트릭스 하나 만들고
		int row;
		int col;
		srand((int)time(NULL));
		cout << "row 의 수를 입력해주세요";
		cin >> row;
		cout << "col 의 수를 입력해주세요";
		cin >> col;
		matrix.SetSize(row, col); //받은 row, col에 맞춰서 매트릭스 만들어줌
		for (int i = 0;i < row;i++)
			for (int j = 0;j < col;j++)
				matrix.StoreItem(rand() % 10, i, j); //0~9까지의 랜덤한 수를 저장함
		vec_mat.push_back(matrix); //벡터에 메트릭스를 넣어줌
		break;
	}
	case menu::AddMatrices:
	{
		if (vec_mat.size() < 2)
			cout << "매트릭스 수가 2개보다 적어 계산이 불가능합니다" << endl;
		else
		{
			int mat_idx1, mat_idx2;
			cout << "더 할 매트릭스의 위치를 입력해주세요(현재 가진 매트릭스 idx: 0 ~ " <<vec_mat.size()-1<<endl;
			cin >> mat_idx1 >> mat_idx2;

			if (mat_idx1<0 || mat_idx2<0 || mat_idx1 > vec_mat.size() - 1 || mat_idx2 > vec_mat.size() - 1) //<vector> asd.size() 는 반환형이 unsigned int이다.
				//나중에할떄는 오류가 날수도 있으니 꼭 size()를 인트로 한번 받고 비교를 진행하자!
				cout << "만들어진 매트릭스의 위치를 벗어났습니다" << endl;
			else
			{
				MatrixType result;
				vec_mat[mat_idx1].Add(vec_mat[mat_idx2], result);
				vec_mat.push_back(result);
				cout << "값이 더해졌씁니다" << endl;
			}
		}
		break;
	}
	case menu::SubMatrices:
	{
		if (vec_mat.size() < 2)
			cout << "매트릭스 수가 2개보다 적어 계산이 불가능합니다" << endl;
		else
		{
			int mat_idx1, mat_idx2;
			cout << "뺴기를 진행할 매트릭스의 위치를 입력해주세요(현재 가진 매트릭스 idx: 0 ~ " << vec_mat.size() - 1 << endl;
			cin >> mat_idx1 >> mat_idx2;

			if (mat_idx1<0 || mat_idx2<0 || mat_idx1 > vec_mat.size() - 1 || mat_idx2 > vec_mat.size() - 1)
				cout << "만들어진 매트릭스의 위치를 벗어났습니다" << endl;
			else
			{
				MatrixType result;
				vec_mat[mat_idx1].Sub(vec_mat[mat_idx2], result);
				vec_mat.push_back(result);
				cout << "값이 빼졌습니다" << endl;
			}
		}
		break;
	}

	case menu::MultiplyMatrices:
	{
		if (vec_mat.size() < 2)
			cout << "매트릭스 수가 2개보다 적어 계산이 불가능합니다" << endl;
		else
		{
			int mat_idx1, mat_idx2;
			cout << "곱할 매트릭스의 위치를 입력해주세요(현재 가진 매트릭스 idx: 0 ~ " << vec_mat.size() - 1 << endl;
			cin >> mat_idx1 >> mat_idx2;

			if (mat_idx1<0 || mat_idx2<0 || mat_idx1 > vec_mat.size() - 1 || mat_idx2 > vec_mat.size() - 1)
				cout << "만들어진 매트릭스의 위치를 벗어났습니다" << endl;
			else
			{
				MatrixType result;
				vec_mat[mat_idx1].Mult(vec_mat[mat_idx2], result);
				vec_mat.push_back(result);
				cout << "값이 곱해졌습니다." << endl;
			}
		}
		break;
	}

	case menu::PrintMatrix:
	{
		if (vec_mat.size() == 0)
			cout << "값을 저장할 매트릭스가 없습니다" << endl;
		else
		{
			ofstream outfile;
			int mat_idx;
			cout<<"값을 저장할 매트릭스의 번호를 입력해주세요(현재 가진 매트릭스 idx: 0 ~ " << vec_mat.size() - 1 << endl;
			cin >> mat_idx;

			if (mat_idx > vec_mat.size() - 1)
				cout << "만들어진 매트릭스의 위치를 벗어났습니다" << endl;
			else
			{
				vec_mat[mat_idx].Print(outfile);
				cout << mat_idx << " 번째 배열이 저장되었습니다." << endl;
			}
		}
		break;
	}
	case menu::Quit:
	{
		cout << "프로그램을 종료합니다" << endl;
		break;
	}

	default:
	{	
		cout << "메뉴의 범위를 벗어났습니다 다시해주세요" << endl;
		break;
	}
	}
}