#include "TQueue.h"
TQueue::TQueue(int s)
{
	try 
	{
		if (s > 0)
		{
			pMem = new int[s];
			sz = s;
			head = 0;
			//tail = s - 1;
			tail = 0;
			count = 0;
		}
		else throw 123;

	}
	catch (int x)
	{
		std::cout << "Error\n";
	}
	
}
void TQueue::Push(const int& val)
{
	pMem[tail] = val;
	tail = (tail + 1) % sz;
	count++;
}
int TQueue::Pop()
{
	
	int val = pMem[head];
	head = (head + 1) % sz;
	count--;
	return val;
}