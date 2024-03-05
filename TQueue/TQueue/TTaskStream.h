#pragma once
#include <cstdlib>
class TTaskStream
{
	int intensity;
public:
	TTaskStream(int num)
	{
		intensity = num;
	}
	bool IsNewTask()
	{
		int num = rand() % 100;
		return (num < intensity);
	}
};

