#include "stdafx.h"
#include <iostream>
#include <string>
#include "vector.h"


template <typename TYPE> int TArray<TYPE>::length() {
	return endData - begData;
}

template <typename TYPE> bool TArray<TYPE>::isEmpty() {
	return length()==0;
}

template <typename TYPE> void TArray<TYPE>::create(int beg, int len, int capacity) {
	if (capacity < 1) {
		capacity = 1;
	}

	if (len < 0) {
		len = 0;
	}
	size = capacity;
	begData = beg;
	endData = beg + len;
	data = new TYPE[capacity];
}

template <typename TYPE> void TArray<TYPE>::show() {
	for (int i = begData; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template <typename TYPE> TArray<TYPE>::TArray() {
	create(0, 0, 1);
}

template <typename TYPE> TArray<TYPE>::TArray(int n) {
	create(0, n, n);
}

template <typename TYPE> TArray<TYPE>::~TArray() {
	delete[]data;
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::clear() {
	delete[]data;
	create(0, 1, 1);
	return *this;
}

template <typename TYPE> void TArray<TYPE>::moveArray(int beg, int end, TYPE *tempArray) {
	for (int i = beg; i < end; ++i) {
		data[begData + i] = tempArray[i];
	}
	delete[]tempArray;
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::pushFront(TYPE a) {
	if (begData == 0) {
		TYPE *temp = data;
		create(begData + length() / 2 + 1, length(), size + length() / 2 + 1);
		moveArray(0,length(),temp);
	}
	--begData;
	data[begData] = a;
	return *this;
}

template <typename TYPE> TArray<TYPE>& TArray<TYPE>::pushBack(TYPE a) {
	if (endData == size) {
		TYPE *temp = data;
		create(begData, length(), size + length() / 2 + 1);
		moveArray(begData, endData, temp);
	}
	data[endData] = a;
	++endData;
	return *this;
}

template <typename TYPE> TYPE TArray<TYPE>::popFront() {
	if (begData > length()) {
		TYPE *temp = data;
		int begTemp = begData;
		create(0, length(), size - begData);
		for (int i = 0; i < length(); ++i){
			data[i] = temp[begTemp + i];
		}
		delete[]temp;
	}
	if (length() > 0) {
		++begData;
	}
	return data[begData - 1];
}

template <typename TYPE> TYPE TArray<TYPE>::popBack() {
	if (size - endData > length()) {
		TYPE *temp = data;
		create(begData, length(), endData);
		for (int i = begData; i < endData; ++i)
			data[i] = temp[i];
		delete[]temp;
	}
	if (length() > 0) {
		--endData;
	}
	return data[endData];
}

template <typename TYPE> TYPE& TArray<TYPE>::operator [] (int i) {
	return data[begData + i];
}
