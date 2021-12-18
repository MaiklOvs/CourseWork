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
	"��������� ����",
	"��������� Steam",
	"��������� Dota 2",
	"�������� ����",
	"���������� ����",
	};
	int n;
	do
	{
		std::cout << "0 - ��������� ���������" << std::endl << "1 - ��������� ����������� �����"
		<< std::endl << "2 - ����������� ������" << std::endl << "3 - ����������� ���������� �����"
		<< std::endl << "4 - ��������� ������ ������" << std::endl << "5 - ������� �����" << std::endl;
		std::cin >> n;
		switch (n)
		{
		case 0: {
			std::cout << "������ �������, ��������� ��������� �������";
			break;
		}
		case 1: {
			for (auto i = 0; i < rand() % 5 ; i++)
			{
				queue.push(GetRandomTask(a));
			}

			std::cout << "\t" << "������ ������� �������������" << std::endl;
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
			std::cout << "\t" << "���������� ����� = " << "\t" << queue.GetSize() << std::endl;
			break;
		}
		case 4: {
			queue.pop();
			queue.PrintQueue();
			break;
		}
		case 5: {
			queue.Clear();
			std::cout << "\t" << "������� �����" << std::endl << "\t"
				<< "���������� ����� = " << queue.GetSize() << std::endl;
			break;
		}
		default: std::cout << "\t" << "����������� �������" << std::endl;
			break;
		}

	} while (n != 0);

	return 0;
}