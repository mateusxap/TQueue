#pragma once
#include <cstdlib>
class TProc
{
	int power;
public:
	TProc(int num) { power = num; }
	bool IsFree(bool prev)
	{
		bool res = true;
		if (prev)
		{
			int num = rand() % 100;
			res = num < power;
		}
		return res;
	}
};

