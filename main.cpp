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
	for (auto i = 0; i < rand() % 5; i++)
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
	}
	scheduler.tasks.print();
}

/// <summary>
/// Завершение задачи
/// </summary>
/// <param name="scheduler"></param>
void CompleteTask(Scheduler& scheduler)
{
	if (scheduler.tasks.Empty())
	{
		std::cout << "\t" << "В данных момент задач нет" << std::endl;
	}
	scheduler.tasks.Delete();
	scheduler.tasks.print();
}

/// <summary>
/// Очистка
/// </summary>
/// <param name="scheduler"></param>
void Clear(Scheduler& scheduler)
{
	scheduler.tasks.clear();
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
void App(Scheduler &scheduler)
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
	};
	do
	{
			WelcomActions();
			std::cin >> n;
			switch (n)
					{
					case (stop): {
						std::cout << "Задачи очищены, программа завершена успешно"<<std::endl;
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
						std::cout << "\t" << "Количество задач = "<< scheduler.tasks.GetSize() << std::endl;
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

int main() {
	setlocale(LC_ALL, "Russian");
	Scheduler scheduler;
	App(scheduler);
	return 0;
}