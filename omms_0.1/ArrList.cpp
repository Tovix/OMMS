#include "ArrList.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <class T>
ArrList<T>::ArrList()
{
	cnt = 0;
	size = 10;
	arr = new T[size];
}

template<class T>
int ArrList<T>::Length()
{
	return cnt;
}

template<class T>
void ArrList<T>::Append(T val)
{
	if (cnt == size)
	{
		Expand();
	}
	arr[cnt] = val;
	cnt++;
}

template<class T>
void ArrList<T>::Expand()
{
	size *= 2;
	T* tmp = new T[size];
	for (int i = 0; i < cnt; i++)
	{
		tmp[i] = arr[i];
	}
	delete arr;
	arr = tmp;
}

template<class T>
void ArrList<T>::Display()
{
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i] << endl;
	}

}

template<class T>
T ArrList<T>::At(int pos)
{
	assert((pos >= 0) & (pos < cnt));
	return arr[pos];
}

template<class T>
void ArrList<T>::insertAt(int pos, T val)
{
	assert(pos >= 0 && pos < cnt);
	if (cnt == size)
	{
		Expand();
	}
	for (int i = cnt; i > pos; i--)
	{
		arr[i] == arr[i - 1];
	}
	arr[pos] = val;
	cnt++;

}

template<class T>
void ArrList<T>::deleteAt(int pos)
{
	for (int i = pos; i < cnt - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	assert(pos >= 0 && pos < cnt);
	cnt--;
}

template<class T>
ArrList<T>::~ArrList(void)
{
	delete[] arr;
}
