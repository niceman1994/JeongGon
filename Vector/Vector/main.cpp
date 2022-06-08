// Vector v0.9
#include <iostream>
#include<algorithm>

using namespace std;

// 원소의 개수
int Size = 0;

// 최대 수용 개수
int Capacity = 0;

// 컨테이너
int* Vector = nullptr;

// 컨테이너의 마지막 위치에 값을 추가
void push_back(const int& _Value);
void pop_back();
int front();
int back();
void erase(const int& _where);
void insert(const int& _index, const int& _Value2);

int main(void)
{
	// 누적된 횟수만큼 비효율적
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100); // f12를 누를경우 지정한 함수의 정의로 이동한다

	pop_back();
	push_back(10000);

	erase(3);
	insert(5, 120);

	cout << "front : " << front() << endl;
	cout << "back : " << back() << endl << endl;

	for (int i = 0; i < Size; ++i)
		cout << "Value : " << Vector[i] << endl;

	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	return 0;
}

void push_back(const int& _Value)
{
	if (Capacity <= Size)
	{
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		int* Temp = new int[Capacity + 1];

		/*for (int i = 0; i < Capacity; ++i)
			Vector[i]= NULL;*/

		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		Temp[Size] = _Value;
		Vector = Temp;
	}
	else
		Vector[Size] = _Value;

	++Size;

	cout << "Value : " << _Value << endl;
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;

	// 추가할 공간이 없을때만 수용량이 추가되도록 코드를 수정
	/*Capacity += (Capacity <= 3) ? 1 : (Capacity > Size ? 0 : Capacity >> 1);

	int* Temp = new int[Capacity];

	for (int i = 0; i < Size; ++i)
		Temp[i] = Vector[i];

	if (Vector)
	{
		delete Vector;
		Vector = nullptr;
	}

	Temp[Size] = _Value;
	++Size;

	Vector = Temp;*/
}

void pop_back()
{
	--Size;
}

int front()
{
	return Vector[0];
}

int back()
{
	return Vector[Size - 1];
}

void erase(const int& _where)
{
	// 특정 위치에 있는 원소를 삭제하고 정렬
	
	--Size;
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
}

void insert(const int& _index, const int& _Value2)
{
	// 특정 위치에 삽입할 수 있는 insert 함수 만들기

	if (Capacity <= Size)
	{
		Capacity += (Capacity <= 3) ? 1 : Capacity >> 1;

		int* Temp = new int[Size + 1];

		for (int i = 0; i < _index; ++i)
			Temp[i] = Vector[i];

		for (int i = _index; i < Size; ++i)
			Temp[i + 1] = Vector[i];

		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		Temp[_index] = _Value2;
		Vector = Temp;
	}
	else
	{
		int* Temp = new int[Size + 1];

		for (int i = 0; i < _index; ++i)
			Temp[i] = Vector[i];

		for (int i = _index; i < Size; ++i)
			Temp[i + 1] = Vector[i];

		Temp[_index] = _Value2;
		Vector = Temp;
	}

	++Size;

	cout << "Value : " << _Value2 << endl;
	cout << "Size : " << Size << endl;
	cout << "Capacity : " << Capacity << endl << endl;
}



// 배열의 특징
/*
	장점
	1. 직접 접근이 가능하다.
	2. 데이터가 나열되어서 접근 속도가 일정하다.
	3. 데이터나 텍스처를 불러오기 좋다.

	단점
	1. 배열의 동적 변환이 불가능하다.(길이가 정해지면 바꿀 수 없다)
	2. 데이터를 어디에 뒀는지 알 수 없다.
	3. 오브젝트를 담기에는 비효율적이기에 사용하지 않는다.
*/

// 이동이 복제보다 빠르다.

	// ** 1. 데이터 추가 (새로운 공간 확보)
	// ** 2. 데이터 삭제
	// ** 3. 데이터를 삽입할 수 있는 공간의 크기
	// ** 4. 현재 삽입되어있는 원소의 개수
	// ** 5. 컨테이너의 시작 지점
	// ** 6. 컨테이너의 종료 지점