#pragma once

template <class T>
class ArrList
{
	T* arr;
	int size, cnt;
public:
	ArrList();
	int Length();
	void Append(T);
	void Expand();
	void Display();
	T At(int);
	void insertAt(int, T);
	void deleteAt(int);
	~ArrList(void);
};