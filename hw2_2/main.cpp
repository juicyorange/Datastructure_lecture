#include "SquareMatrix.h"
#include <Windows.h>
using namespace std;

void main()
{
	//주석 TEST DRIVER 내용
	//크기설정까지는 50이라 입력해도 들어감. 하지만 2차원배열에 값을 넣거나 다른작업을 할떄에는
	//크기 50짜리 배열을 만들면 0~49까지 만들어진다는 것을 생각하고 값을 넣어야함.
	SquareMatrix A1;
	SquareMatrix A2(-2); //1보다 작은값 넣어보고 메시지 출력되는지 확인
	SquareMatrix A3(51); //50보다 큰값 넣어보고 메시지 출력되는지 확인
	SquareMatrix A4(15);  // 정상적으로 작동하는지 확인
	cout << endl << "           생성자 확인" << endl;
	A4.StoreValue(-1, 5, 3); // 하나만 음수넣고 메시지 출력되는지 확인
	A4.StoreValue(12, 25, 3); // 최대로 설정한 크기보다 큰 값을 넣으면 메시지 출력되는지 A1의 최대크기는 위에서 25로 정해줌.
	A4.StoreValue(14, 14, 3); // 정상적으로 작동하나 확인
	A4.StoreValue(13, 13, 2);
	A4.StoreValue(12, 12, 1);
	A4.Printall();
	cout << endl <<   "          특정위치에 값 넣기 확인" << endl;

	A4.MakeEmpty(-2);  //0보다 작은값 넣어보고 메시지 출력되는지 확인
	A4.MakeEmpty(15); //최대크기보다보다 큰값 넣어보고 메시지 출력되는지 확인
	A4.MakeEmpty(13); // 정상적으로 작동하나 확인
	A4.Printall();
	cout << endl << "           빈 매트릭스 만들기 확인" << endl;
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

	cout << endl << "                테스트를 위한 매트릭스 만들기" << endl;
	A5.Printall();  // 값들이 잘 들어갔는지 확인
	cout << endl;
	A6.Printall();  // 값들이 잘 들어갔는지 확인
	cout << endl;

	cout << endl << "                 매트릭스에 값 알맞게 들어갔는지 확인" << endl;
	SquareMatrix Add_check;
	Add_check.Add(A1, A5); // 크기가 다른 배열 넣기
	Add_check.Add(A5, A6); //더하기 하고
	cout << endl;
	Add_check.Printall();  // 더하기가 잘 되었는지

	cout << endl << "                더하기 확인" << endl;

	SquareMatrix Sub_check;
	Sub_check.Sub(A1, A5); // 크기가 다른 배열 넣기
	Sub_check.Sub(A5, A6); // 빼기 하고
	cout << endl;
	Sub_check.Printall();  // 빼기가 잘 되었는지

	cout << endl << "               빼기 확인" << endl;
	SquareMatrix Copy_check;
	Copy_check.Copy(Sub_check);
	Copy_check.Printall(); // 복사가 잘 되었는지.


	cout << endl << "               복사 확인" << endl;

	system("pause");
}