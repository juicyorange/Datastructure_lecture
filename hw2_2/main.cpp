#include "SquareMatrix.h"
#include <Windows.h>
using namespace std;

void main()
{
	//�ּ� TEST DRIVER ����
	//ũ�⼳�������� 50�̶� �Է��ص� ��. ������ 2�����迭�� ���� �ְų� �ٸ��۾��� �ҋ�����
	//ũ�� 50¥�� �迭�� ����� 0~49���� ��������ٴ� ���� �����ϰ� ���� �־����.
	SquareMatrix A1;
	SquareMatrix A2(-2); //1���� ������ �־�� �޽��� ��µǴ��� Ȯ��
	SquareMatrix A3(51); //50���� ū�� �־�� �޽��� ��µǴ��� Ȯ��
	SquareMatrix A4(15);  // ���������� �۵��ϴ��� Ȯ��
	cout << endl << "           ������ Ȯ��" << endl;
	A4.StoreValue(-1, 5, 3); // �ϳ��� �����ְ� �޽��� ��µǴ��� Ȯ��
	A4.StoreValue(12, 25, 3); // �ִ�� ������ ũ�⺸�� ū ���� ������ �޽��� ��µǴ��� A1�� �ִ�ũ��� ������ 25�� ������.
	A4.StoreValue(14, 14, 3); // ���������� �۵��ϳ� Ȯ��
	A4.StoreValue(13, 13, 2);
	A4.StoreValue(12, 12, 1);
	A4.Printall();
	cout << endl <<   "          Ư����ġ�� �� �ֱ� Ȯ��" << endl;

	A4.MakeEmpty(-2);  //0���� ������ �־�� �޽��� ��µǴ��� Ȯ��
	A4.MakeEmpty(15); //�ִ�ũ�⺸�ٺ��� ū�� �־�� �޽��� ��µǴ��� Ȯ��
	A4.MakeEmpty(13); // ���������� �۵��ϳ� Ȯ��
	A4.Printall();
	cout << endl << "           �� ��Ʈ���� ����� Ȯ��" << endl;
	SquareMatrix A5(5);
	SquareMatrix A6(5);

	A5.StoreValue(1, 1, 1);
	A5.StoreValue(2, 2, 2);
	A5.StoreValue(3, 3, 3);
	A5.StoreValue(4, 4, 4);

	A6.StoreValue(1, 1, 2);
	A6.StoreValue(2, 2, 4);
	A6.StoreValue(3, 3, 6);
	A6.StoreValue(4, 4, 8);

	cout << endl << "                �׽�Ʈ�� ���� ��Ʈ���� �����" << endl;
	A5.Printall();  // ������ �� ������ Ȯ��
	cout << endl;
	A6.Printall();  // ������ �� ������ Ȯ��
	cout << endl;

	cout << endl << "                 ��Ʈ������ �� �˸°� ������ Ȯ��" << endl;
	SquareMatrix Add_check;
	Add_check.Add(A1, A5); // ũ�Ⱑ �ٸ� �迭 �ֱ�
	Add_check.Add(A5, A6); //���ϱ� �ϰ�
	cout << endl;
	Add_check.Printall();  // ���ϱⰡ �� �Ǿ�����

	cout << endl << "                ���ϱ� Ȯ��" << endl;

	SquareMatrix Sub_check;
	Sub_check.Sub(A1, A5); // ũ�Ⱑ �ٸ� �迭 �ֱ�
	Sub_check.Sub(A5, A6); // ���� �ϰ�
	cout << endl;
	Sub_check.Printall();  // ���Ⱑ �� �Ǿ�����

	cout << endl << "               ���� Ȯ��" << endl;
	SquareMatrix Copy_check;
	Copy_check.Copy(Sub_check);
	Copy_check.Printall(); // ���簡 �� �Ǿ�����.


	cout << endl << "               ���� Ȯ��" << endl;

	system("pause");
}