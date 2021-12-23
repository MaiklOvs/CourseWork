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
/// �����������
/// </summary>
class Scheduler
{
public:
	Queue tasks;
};
/// <summary>
/// ������� ��������� �����������
/// </summary>
/// <param name="scheduler"></param>
void app(Scheduler &scheduler)
{
	Actions action = Stop;
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
			std::cout << "��������� ��������� - 1" << std::endl << "��������� ����������� ����� - 2"
			<< std::endl << "����������� ������ - 3" << std::endl << "����������� ���������� ����� - 4"
			<< std::endl << "��������� ������ ������ - 5" << std::endl << "������� ����� - 6" << std::endl;
			std::cin >> n;
			switch (n)
					{
					case (Stop): {
						std::cout << "������ �������, ��������� ��������� �������"<<std::endl;
						return;
						
					}
					case (Start): {
						for (auto i = 0; i < rand() % 5 ; i++)
						{
							scheduler.tasks.AddTask((GetRandomTask(a)));
						}

						std::cout << "\t" << "������ ������� �������������" << std::endl;
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
						std::cout << "\t" << "���������� ����� = "<< scheduler.tasks.GetSize() << std::endl;
						break;
					}
					case (CompleteTask): {
						scheduler.tasks.DeleteTask();
						scheduler.tasks.PrintTasks();
						break;
					}
					case (Clear): {
						scheduler.tasks.Clear();
						std::cout << "\t" << "������� �����" << std::endl << "\t"
							<< "���������� ����� = " << scheduler.tasks.GetSize() << std::endl;
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
	app(scheduler);
	return 0;
}