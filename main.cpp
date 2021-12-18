#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "GetRandomTask.h"
enum Actions
{
	Stop = 1,
	Start,
	PrintTasks,
	PrintCountTasks,
	CompleteTask,
	Clear
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
/// Функция программы иллюстратор
/// </summary>
/// <param name="scheduler"></param>
void app(Scheduler &scheduler)
{
	Actions action = Stop;
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
			std::cout << "Завершить программу - 1" << std::endl << "Запустить планировщик задач - 2"
			<< std::endl << "Распечатать задачи - 3" << std::endl << "Распечатать количество задач - 4"
			<< std::endl << "Выполнить первую задачу - 5" << std::endl << "Очистка задач - 6" << std::endl;
			std::cin >> n;
			switch (n)
					{
					case (Stop): {
						std::cout << "Задачи очищены, программа завершена успешно"<<std::endl;
						return;
						
					}
					case (Start): {
						for (auto i = 0; i < rand() % 5 ; i++)
						{
							scheduler.tasks.AddTask((GetRandomTask(a)));
						}

						std::cout << "\t" << "Задачи успешно сгенерированы" << std::endl;
						break;
					}
					case (PrintTasks): {
						/*PrintTasksQueue();
						{

						}
						*/
						scheduler.tasks.PrintTasks();
						break;
					}
					case (PrintCountTasks): {
						std::cout << "\t" << "Количество задач = "<< scheduler.tasks.GetSize() << std::endl;
						break;
					}
					case (CompleteTask): {
						scheduler.tasks.DeleteTask();
						scheduler.tasks.PrintTasks();
						break;
					}
					case (Clear): {
						scheduler.tasks.Clear();
						std::cout << "\t" << "Очистка задач" << std::endl << "\t"
							<< "Количество задач = " << scheduler.tasks.GetSize() << std::endl;
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
	app(scheduler);
	return 0;
}