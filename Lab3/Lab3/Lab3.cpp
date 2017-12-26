// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename TYPE>
class TArray
{
private:
	int size, begData, endData;
	TYPE *data;
	void create (int mem, int len, int beg);
public:
	TArray(int n);
	TArray();
	~TArray();
	int length();
	bool isEmpty();
	void show();
	TArray& clear ();
	TArray& init(int n);
	TArray& pushFront(TYPE a);
	TArray& pushBack(TYPE a);
	TYPE popFront();
	TYPE popBack();
	TYPE& operator [] (int i);
};

int main()
{
	TArray<int> A;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		A.pushBack(t);
	}
	cout << A.isEmpty() << endl;

	system("pause");
    return 0;
}

template <typename TYPE> int TArray<TYPE>::length() {
	return endData - begData;
}

template <typename TYPE> bool TArray<TYPE>::isEmpty() {
	return length() < 0 ? true : false;
}

template <typename TYPE> void TArray<TYPE>::create(int mem, int len, int beg) {
	if (mem < 1) {
		mem = 1;
	}
	
	if (len < 0){
		len = 0;
	}
	size = mem;
	begData = beg;
	endData = beg + len;
	data = new TYPE[mem];
}

template <typename TYPE> void TArray<TYPE>::show() {
	TYPE *tmp = data;
	while (length()){
		cout << popFront() << " ";
	}
}

template <typename TYPE> TArray<TYPE>::TArray() {
	create(1,0,0);
}

template <typename TYPE> TArray<TYPE>::TArray(int n) {
	create(n,n,0);
}

template <typename TYPE> TArray<TYPE>::~TArray() {
	delete []data;
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::clear () {
	delete[]data;
	create(1,1,0);
	return *this;
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::init (int n) {
	delete[]data;
	create(n, n, 0);
	return *this;
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::pushFront(TYPE a) {
	if (begData == 0) {
		TYPE *temp = data;
		create(size + length() / 2 + 1, length(), begData + length() / 2 + 1);
		for (int i = 0; i < length(); ++i){
			data[begData + i] = temp[i];
		}
		delete []temp;
	}
	--begData;
	data[begData] = a;
	return *this; 
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::pushBack(TYPE a) {
	if (endData == 0) {
		TYPE *temp = data;
		create(size + length() / 2 + 1, length(), begData);
		for (int i = begData; i < endData; ++i) {
			data[i] = temp[i];
		}
		delete[]temp;
	}
	data[endData] = a;
	++endData;
	return *this;
}

template <typename TYPE> TYPE TArray<TYPE>::popFront() {
	if (begData > length()){
		TYPE *temp = data;
		int begTemp = begData;
		create(size - begData, length(), 0);
		for (int i = 0; i < length(); ++i){
			data[i] = temp[begTemp + i];
		}
		delete []temp;
	}
	if (length() > 0) {
		++begData;
	}
	return data[begData - 1];
}

template <typename TYPE> TYPE TArray<TYPE>::popBack() {
	if (size - endData > length()) {
		TYPE *temp = data;
		create(endData, length(), begData);
		for (int i = begData; i < endData; ++i) {
			data[i] = temp[i];
		}
		delete[]temp;
	}
	if (length() > 0) {
		--endData;
	}
	return data[endData];
}

template <typename TYPE> TYPE& TArray<TYPE>::operator [] (int i){
	if (i < 0) {
		i = 0;
	}
	else if (i >= length()) {
		i = length() - 1;
	}
	return data[begData + i];
}
