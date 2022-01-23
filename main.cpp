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
/// Планировщик
/// </summary>
class Scheduler
{
public:
	Queue tasks;
};

/// <summary>
/// Старт
/// </summary>
/// <param name="scheduler"></param>
/// <param name="a"></param>
void Start(Scheduler& scheduler, std::vector <std::string>& a)
{
	for (auto i = 0; i < rand() % 7; i++)
	{
		scheduler.tasks.Add((GetRandomTask(a)));
	}
	
	std::cout << "\t" << "Задачи успешно сгенерированы" << std::endl;
	
}

/// <summary>
/// Распечатка
/// </summary>
/// <param name="scheduler"></param>
void Print(Scheduler& scheduler)
{
	if (scheduler.tasks.Empty())
	{
		std::cout << "\t" << "В данных момент задач нет" << std::endl;
		return;
	}
	scheduler.tasks.print();
}

/// <summary>
/// Завершение задачи
/// </summary>
/// <param name="scheduler"></param>
bool CompleteTask(Scheduler& scheduler)
{
	if (scheduler.tasks.Empty())
	{
		std::cout << "\t" << "В данных момент задач нет" << std::endl;
		
	}
	else 
	{
	scheduler.tasks.Delete();
	scheduler.tasks.print();
	return true;
	}
}

/// <summary>
/// Очистка
/// </summary>
/// <param name="scheduler"></param>
void Clear(Scheduler& scheduler)
{
	scheduler.tasks.Clear();
	std::cout << "\t" << "Очистка задач" << std::endl << "\t"
		<< "Количество задач = " << scheduler.tasks.GetSize() << std::endl;
}

/// <summary>
/// Предлагаемые действия
/// </summary>
void WelcomActions()
{
		std::cout << "Завершить программу - 1" << std::endl << "Запустить планировщик задач - 2"
		<< std::endl << "Распечатать задачи - 3" << std::endl << "Распечатать количество задач - 4"
		<< std::endl << "Выполнить первую задачу - 5" << std::endl << "Очистка задач - 6" << std::endl;
}

/// <summary>
/// Функция программы иллюстратор
/// </summary>
/// <param name="scheduler"></param>
void App(Scheduler& scheduler)
{
	Actions action = stop;
	int n = action;
	std::vector<std::string> a =
	{
	"Запустить гугл",
	"Запустить Steam",
	"Запустить Dota 2",
	"Свернуть окно",
	"Развернуть окно",
	"Включить спотифай",
	"Выключить спотифай"
	};
	do
		{
			WelcomActions();
			std::cin >> n;
			switch (n)
			{
			case (stop): {
				Clear(scheduler);
				std::cout << "Задачи очищены, программа завершена успешно" << std::endl;
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
				std::cout << "\t" << "Количество задач = " << scheduler.tasks.GetSize() << std::endl;
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
			default: std::cout << "\t" << "Неизвестная команда" << std::endl;
				break;
			}
		} while (n != 1);
	
	
}

/// <summary>
/// Тестирование функции Clear
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
/// Тестрирование функции Start
/// </summary>
/// <param name="scheduler"></param>
/// <param name="a"></param>
/// <returns></returns>
bool TestSchedulerStart(Scheduler& scheduler)
{
	std::vector<std::string> a =
	{
	"Запустить гугл",
	"Запустить Steam",
	"Запустить Dota 2",
	"Свернуть окно",
	"Развернуть окно",
	"Включить спотифай",
	"Выключить спотифай"
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
/// Тестирование функции CompleteTask
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
/// Функция тестирования
/// </summary>
/// <returns></returns>
void Test(Scheduler& scheduler)
{
	
	
	std::cout << "Тестирование функции CompleteTask" << std::endl;
	std::cout<<"error = "<< TestScheduler_CompleteTask(scheduler) << std::endl;


	std::cout << "Тестирование функции Clear" << std::endl;
	std::cout << "error = " << TestSchedulerClear(scheduler) << std::endl;

	std::cout << "Тестирование функции Start" << std::endl;
	std::cout << "error = " << TestSchedulerStart(scheduler) << std::endl;
};

int main() {
	setlocale(LC_ALL, "Russian");
	Scheduler scheduler;
	Actions action = stop;
	int n = action;
	std::cout << "В каком режиме запустить программу? 7 - test 8 - application" << std::endl;
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