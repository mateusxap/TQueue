#pragma once
#include <iostream>
#include <stdlib.h>
class TQueue
{
	int head;
	int tail;
	int sz;
	int count;
	int* pMem;
public:
	TQueue(int s);
	int Count() const		{ return count; }
	bool IsEmpty() const	{ return count == 0; }
	bool IsFull() const		{ return sz == count; }
	void Push(const int& val);
	int Pop();
};

