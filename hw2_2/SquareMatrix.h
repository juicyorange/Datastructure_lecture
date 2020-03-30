#pragma once
#include<iostream>
const int MAX_ROWS = 50;

class SquareMatrix
{
private:
	int n; //정사각형이므로 행이나 열 둘중 하나만 받아도 되므로 하나만 만들기
	int Mat[50][50]; //최대크기가 50으로 정해져있으므로 동적할당 하지말자
public:
	SquareMatrix(); //아무것도 안넣으면 n=0이고, n=0이므로 배열을 초기화 할 필요 없음
	SquareMatrix(int num);
	void MakeEmpty(int num); //모든 n행과 열들을 0으로 설정한다.
	void StoreValue(int i, int j, int value); //value를 i번째행, j번째 열의 위치에 저장한다.
	void Add(SquareMatrix& A1, SquareMatrix& A2); //1번째 2번째는 더하기 진행할 매트릭스
	void Sub(SquareMatrix& A1, SquareMatrix& A2); //1번째 2번째는 빼기를 진행할 매트릭스
	void Copy(SquareMatrix& A1); //1번쨰는 복사할 대상
	void Printall();

};
