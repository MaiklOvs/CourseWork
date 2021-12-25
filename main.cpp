#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "GetRandomTask.h"
enum Actions
{
	stop = 1,
	start,
	print,
	printCountTasks,
	completeTask,
	clear
};

/// <summary>
/// �����������
/// </summary>
class Scheduler
{
public:
	Queue tasks;
};

/// <summary>
/// �����
/// </summary>
/// <param name="scheduler"></param>
/// <param name="a"></param>
void Start(Scheduler& scheduler, std::vector <std::string>& a)
{
	for (auto i = 0; i < rand() % 5; i++)
	{
		scheduler.tasks.Add((GetRandomTask(a)));
	}
	std::cout << "\t" << "������ ������� �������������" << std::endl;
}

/// <summary>
/// ����������
/// </summary>
/// <param name="scheduler"></param>
void Print(Scheduler& scheduler)
{
	if (scheduler.tasks.Empty())
	{
		std::cout << "\t" << "� ������ ������ ����� ���" << std::endl;
	}
	scheduler.tasks.print();
}

/// <summary>
/// ���������� ������
/// </summary>
/// <param name="scheduler"></param>
void CompleteTask(Scheduler& scheduler)
{
	if (scheduler.tasks.Empty())
	{
		std::cout << "\t" << "� ������ ������ ����� ���" << std::endl;
	}
	scheduler.tasks.Delete();
	scheduler.tasks.print();
}

/// <summary>
/// �������
/// </summary>
/// <param name="scheduler"></param>
void Clear(Scheduler& scheduler)
{
	scheduler.tasks.clear();
	std::cout << "\t" << "������� �����" << std::endl << "\t"
		<< "���������� ����� = " << scheduler.tasks.GetSize() << std::endl;
}

/// <summary>
/// ������������ ��������
/// </summary>
void WelcomActions()
{
		std::cout << "��������� ��������� - 1" << std::endl << "��������� ����������� ����� - 2"
		<< std::endl << "����������� ������ - 3" << std::endl << "����������� ���������� ����� - 4"
		<< std::endl << "��������� ������ ������ - 5" << std::endl << "������� ����� - 6" << std::endl;
}

/// <summary>
/// ������� ��������� �����������
/// </summary>
/// <param name="scheduler"></param>
void App(Scheduler &scheduler)
{
	Actions action = stop;
	int n = action;
	std::vector<std::string> a =
	{
	"��������� ����",
	"��������� Steam",
	"��������� Dota 2",
	"�������� ����",
	"���������� ����",
	};
	do
	{
			WelcomActions();
			std::cin >> n;
			switch (n)
					{
					case (stop): {
						std::cout << "������ �������, ��������� ��������� �������"<<std::endl;
						return;		
					}
					case (start): {
						Start(scheduler, a);
						break;
					}
					case (print): {
						Print(scheduler);
						break;
					}
					case (printCountTasks): {						
						std::cout << "\t" << "���������� ����� = "<< scheduler.tasks.GetSize() << std::endl;
						break;
					}
					case (completeTask): {
						CompleteTask(scheduler);
						break;
					}
					case (clear): {
						Clear(scheduler);
						break;
					}
					default: std::cout << "\t" << "����������� �������" << std::endl;
						break;
					}
	} while (n != 1);
}

int main() {
	setlocale(LC_ALL, "Russian");
	Scheduler scheduler;
	App(scheduler);
	return 0;
}