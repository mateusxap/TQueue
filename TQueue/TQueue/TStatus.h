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
		//����� �������� ���� ������� ������ 20
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
					std::cout << "��������� �����\n";
				}*/
			}//tact - wait / com
		}
		
		else
		{
			
			bool prev = false;
			for (int i = 0; i < _tact; i++)
			{
				std::cout << "\n";
				std::cout << "����� �����: " << i << "\n";
				
				if (stream.IsNewTask())
				{
					std::cout << "��������� ������ " << incoming << "\n";
					if (!queue.IsFull())
					{
						queue.Push(incoming);
						std::cout << "������� �� ������, ������ ��������� � �������  " << "\n";
						incoming++;
					}
					else
					{
						ignored++;
						std::cout << "������ ����������������  " << "\n";
					}
				}
				else
				{
					std::cout << "������ �� ���������\n";
				}
				if (proc.IsFree(prev))
				{
					std::cout << "��������� ��������  " << "\n";
					if (!queue.IsEmpty())
					{
						std::cout << "������� �� ������, ��������� ���� ������ " << queue.Pop()<< "\n";
						//queue.Pop();
						prev = true;
						completed++;
					}
					else
					{
						wait++;
						std::cout << "�������  " << "\n";
						prev = false;
					}
				}
				else
				{
					std::cout << "��������� �����\n";
				}
			}//tact - wait / com
		}
		std::cout << "���������� ����������� �����: " << ((double)incoming) << "\n";
		std::cout << "������� ����������������� �����: " << ((double)ignored / (double)tact) * 100 << "%\n";
		std::cout << "������� ����� ���������� �����: " << ((double)(tact - wait) / (double)completed)  << "\n";
		std::cout << "������� ������� ����������: " << ((double)wait / (double)tact) * 100 << "%\n";
	}
};

