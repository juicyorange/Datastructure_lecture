#pragma once
#include<iostream>
const int MAX_ROWS = 50;

class SquareMatrix
{
private:
	int n; //���簢���̹Ƿ� ���̳� �� ���� �ϳ��� �޾Ƶ� �ǹǷ� �ϳ��� �����
	int Mat[50][50]; //�ִ�ũ�Ⱑ 50���� �����������Ƿ� �����Ҵ� ��������
public:
	SquareMatrix(); //�ƹ��͵� �ȳ����� n=0�̰�, n=0�̹Ƿ� �迭�� �ʱ�ȭ �� �ʿ� ����
	SquareMatrix(int num);
	void MakeEmpty(int num); //��� n��� ������ 0���� �����Ѵ�.
	void StoreValue(int i, int j, int value); //value�� i��°��, j��° ���� ��ġ�� �����Ѵ�.
	void Add(SquareMatrix& A1, SquareMatrix& A2); //1��° 2��°�� ���ϱ� ������ ��Ʈ����
	void Sub(SquareMatrix& A1, SquareMatrix& A2); //1��° 2��°�� ���⸦ ������ ��Ʈ����
	void Copy(SquareMatrix& A1); //1������ ������ ���
	void Printall();

};
