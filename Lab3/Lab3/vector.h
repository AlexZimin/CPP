#pragma once
template <typename TYPE>
class TArray
{
private:
	int size, begData, endData;
	TYPE *data;
	void create(int capacity, int len, int beg);
public:
	TArray(int n);

	TArray();

	~TArray();

	int length();

	bool isEmpty();

	void show();

	void cmpArray(int beg,int end,TYPE *tmp);

	TArray& clear();

	TArray& pushFront(TYPE a);

	TArray& pushBack(TYPE a);

	TYPE popFront();

	TYPE popBack();

	TYPE& operator [] (int i);
};


