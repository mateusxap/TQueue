#pragma once
#include "TProc.h"
#include "TQueue.h"
#include "TTaskStream.h"
class TStatus
{
	TQueue queue;
	TTaskStream stream;
	TProc proc;
	int tact, incoming, wait, ignored, completed;
public:
	TStatus(int _tact, int _intensity, int _counter, int _power) :queue(_counter), proc(_power), stream(_intensity), tact(_tact),ignored(0),wait(0),completed(0),incoming(0)
	{
		//вывод действий если тактовв меньше 20
		if (tact > 20)
		{
			bool prev = false;
			for (int i = 0; i < _tact; i++)
			{
				if (stream.IsNewTask())
				{
					if (!queue.IsFull())
					{
						queue.Push(incoming);
						incoming++;
					}
					else
					{
						ignored++;
					}
				}
				/*else
				{
					...
				}*/
				if (proc.IsFree(prev))
				{
					if (!queue.IsEmpty())
					{
						queue.Pop();
						prev = true;
						completed++;
					}
					else
					{
						wait++;
						prev = false;
					}
				}
				/*else
				{
					std::cout << "Процессор занят\n";
				}*/
			}//tact - wait / com
		}
		
		else
		{
			
			bool prev = false;
			for (int i = 0; i < _tact; i++)
			{
				std::cout << "\n";
				std::cout << "Номер такта: " << i << "\n";
				
				if (stream.IsNewTask())
				{
					std::cout << "Поступила задача " << incoming << "\n";
					if (!queue.IsFull())
					{
						queue.Push(incoming);
						std::cout << "Очередь не полная, задача поступила в очередь  " << "\n";
						incoming++;
					}
					else
					{
						ignored++;
						std::cout << "Задача проигнорированна  " << "\n";
					}
				}
				else
				{
					std::cout << "Задача не поступила\n";
				}
				if (proc.IsFree(prev))
				{
					std::cout << "Процессор свободен  " << "\n";
					if (!queue.IsEmpty())
					{
						std::cout << "Очередь не пустая, процессор взял задачу " << queue.Pop()<< "\n";
						//queue.Pop();
						prev = true;
						completed++;
					}
					else
					{
						wait++;
						std::cout << "Простой  " << "\n";
						prev = false;
					}
				}
				else
				{
					std::cout << "Процессор занят\n";
				}
			}//tact - wait / com
		}
		std::cout << "Количество поступивших задач: " << ((double)incoming) << "\n";
		std::cout << "Процент проигнорированных задач: " << ((double)ignored / (double)tact) * 100 << "%\n";
		std::cout << "Среднее время выполнения задач: " << ((double)(tact - wait) / (double)completed)  << "\n";
		std::cout << "Процент простоя процессора: " << ((double)wait / (double)tact) * 100 << "%\n";
	}
};

