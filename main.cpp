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
	clear,
	test,
	application
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
	for (auto i = 0; i < rand() % 7; i++)
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
		return;
	}
	scheduler.tasks.print();
}

/// <summary>
/// ���������� ������
/// </summary>
/// <param name="scheduler"></param>
bool CompleteTask(Scheduler& scheduler)
{
	if (scheduler.tasks.Empty())
	{
		std::cout << "\t" << "� ������ ������ ����� ���" << std::endl;
		
	}
	else 
	{
	scheduler.tasks.Delete();
	scheduler.tasks.print();
	return true;
	}
}

/// <summary>
/// �������
/// </summary>
/// <param name="scheduler"></param>
void Clear(Scheduler& scheduler)
{
	scheduler.tasks.Clear();
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
void App(Scheduler& scheduler)
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
	"�������� ��������",
	"��������� ��������"
	};
	do
		{
			WelcomActions();
			std::cin >> n;
			switch (n)
			{
			case (stop): {
				Clear(scheduler);
				std::cout << "������ �������, ��������� ��������� �������" << std::endl;
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
				std::cout << "\t" << "���������� ����� = " << scheduler.tasks.GetSize() << std::endl;
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

/// <summary>
/// ������������ ������� Clear
/// </summary>

bool TestSchedulerClear(Scheduler& scheduler)
{
	
	scheduler.tasks.Clear();
	if (scheduler.tasks.Empty() == true)
	{
		Print(scheduler);
		return false;
	}
	else
	{
		return true;
	}

}

/// <summary>
/// ������������� ������� Start
/// </summary>
/// <param name="scheduler"></param>
/// <param name="a"></param>
/// <returns></returns>
bool TestSchedulerStart(Scheduler& scheduler)
{
	std::vector<std::string> a =
	{
	"��������� ����",
	"��������� Steam",
	"��������� Dota 2",
	"�������� ����",
	"���������� ����",
	"�������� ��������",
	"��������� ��������"
	};
  Start(scheduler,a);
  Print(scheduler);
  if (scheduler.tasks.Empty() == false)
  {
	  return false;
  }
  else 
  {
	  return true;
  }
}

/// <summary>
/// ������������ ������� CompleteTask
/// </summary>
/// <param name="scheduler"></param>
/// <returns></returns>
bool TestScheduler_CompleteTask(Scheduler& scheduler)
{
	if (CompleteTask(scheduler))
	{
		return false;
	}
	return true;
}

/// <summary>
/// ������� ������������
/// </summary>
/// <returns></returns>
void Test(Scheduler& scheduler)
{
	
	
	std::cout << "������������ ������� CompleteTask" << std::endl;
	std::cout<<"error = "<< TestScheduler_CompleteTask(scheduler) << std::endl;


	std::cout << "������������ ������� Clear" << std::endl;
	std::cout << "error = " << TestSchedulerClear(scheduler) << std::endl;

	std::cout << "������������ ������� Start" << std::endl;
	std::cout << "error = " << TestSchedulerStart(scheduler) << std::endl;
};

int main() {
	setlocale(LC_ALL, "Russian");
	Scheduler scheduler;
	Actions action = stop;
	int n = action;
	std::cout << "� ����� ������ ��������� ���������? 7 - test 8 - application" << std::endl;
	std::cin >> n;
	switch (n)
	{
	case(application):
		App(scheduler);
		break;
	case(test): 
		Test(scheduler);
		break;
	}
	
	
	return 0;
}