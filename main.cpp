#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "GetRandomTask.h"

/*class Scheduler
{
	Queue tasks;
};
*/

int main() {
	setlocale(LC_ALL, "Russian");
	Queue queue;
	std::vector<std::string> a =
	{
	"Запустить гугл",
	"Запустить Steam",
	"Запустить Dota 2",
	"Свернуть окно",
	"Развернуть окно",
	};
	int n;
	do
	{
		std::cout << "0 - Завершить программу" << std::endl << "1 - Запустить планировщик задач"
		<< std::endl << "2 - Распечатать задачи" << std::endl << "3 - Распечатать количество задач"
		<< std::endl << "4 - Выполнить первую задачу" << std::endl << "5 - очистка задач" << std::endl;
		std::cin >> n;
		switch (n)
		{
		case 0: {
			std::cout << "Задачи очищены, программа завершена успешно";
			break;
		}
		case 1: {
			for (auto i = 0; i < rand() % 5 ; i++)
			{
				queue.push(GetRandomTask(a));
			}

			std::cout << "\t" << "Задачи успешно сгенерированы" << std::endl;
			break;
		}
		case 2: {
			/*PrintTasksQueue();
			{

			}
			*/
			queue.PrintQueue();
			break;
		}
		case 3: {
			std::cout << "\t" << "Количество задач = " << "\t" << queue.GetSize() << std::endl;
			break;
		}
		case 4: {
			queue.pop();
			queue.PrintQueue();
			break;
		}
		case 5: {
			queue.Clear();
			std::cout << "\t" << "Очистка задач" << std::endl << "\t"
				<< "Количество задач = " << queue.GetSize() << std::endl;
			break;
		}
		default: std::cout << "\t" << "Неизвестная команда" << std::endl;
			break;
		}

	} while (n != 0);

	return 0;
}