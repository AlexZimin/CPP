#pragma once
template <typename TYPE>
class TArray
{
private:
	int size, begData, endData;
	TYPE *data;
	void create(int beg, int len, int capacity);
	void moveArray(int beg, int end, TYPE *tmp);
public:
	TArray(int n);

	TArray();

	~TArray();

	int length();

	bool isEmpty();

	void show();


	TArray& clear();

	TArray& pushFront(TYPE a);

	TArray& pushBack(TYPE a);

	TYPE popFront();

	TYPE popBack();

	TYPE& operator [] (int i);
};


