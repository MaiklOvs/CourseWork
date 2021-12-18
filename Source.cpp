#include <iostream>
#include <string>
#include <vector>

/// <summary>
/// ����� ��� ��������� ������ �������
/// </summary>
class Queue
{
public:
	Queue();  //�����������
	~Queue(); //����������
	void push(std::string data); // ���������� �������� � �������
	int GetSize() { return size; } //��������� ���������� ���������
	void PrintQueue(); //���������� ����� �������
	void pop(); // �������� ��������
	void Clear();//������� �������
private:
	/// <summary>
	/// ���� ������
	/// </summary>
	class Node //������� �������
	{
	public:
		Node* next; // ��������� �� ��������� ������� �������
		std::string data; // ������, ������� ������ ������� �������
		Node(std::string data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node* head; //������ ������
	Node* last;
	int size; //����������  ���������

};

/// <summary>
/// �����������
/// </summary>
Queue::Queue()
{
	size = 0;
	head = nullptr;
	last = nullptr;
}
/// <summary>
/// ����������
/// </summary>
Queue::~Queue()
{
	Clear();
}
/// <summary>
/// ���������� �������� � �������
/// </summary>
/// <param name="Data">������� �������</param>
void Queue::push(std::string data)
{
	if (head == nullptr)  //��������, ������ �� ������ �������
	{
		head = new Node(data); // �������� ������� ��������, � ������ ��� ����������
		last = head;
	}

	else
	{
		 last->next = new Node(data); // �������� ������ �������� 
		 last = last->next;
	}
	size++;

}
/// <summary>
/// ���������� ����� �� �������
/// </summary>
/// <param name="a"></param>
void Queue::PrintQueue()
{
	if (size != 0) {
		Node* current = head; // ��������� ���������� ��� ������ ���������� ��������
		for (size_t i = 0; i < GetSize(); i++)
		{
			std::cout << "\t" << current->data << std::endl; //����� ���������� �� ���� Data
			current = current->next; // ������� � ���������� �������� �������
		}
	}
	


}
/// <summary>
/// ���������� ������� ��������
/// </summary>
void Queue::pop()
{
	if (size > 0) {
		Node* temp = head; // ��������� ���������� 
		head = head->next; // ������� � ���������� ��������
		delete temp; // ��������
		size--;

	}
	
}
/// <summary>
/// ������� �������
/// </summary>
void Queue::Clear()
{
	while (size)
	{
		pop();
	}
}
/// <summary>
/// ��������� ��������� ������
/// </summary>
/// <param name="a">������ � ��������</param>
/// <returns></returns>
std::string GetRandomTask(std::vector<std::string>& a) {
	return a[rand() % 5];
}

class Scheduler
{
	Queue tasks;
};

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
			for (size_t i = 0; i < rand() % 10; i++)
			{
				queue.push(GetRandomTask(a));
			}

			std::cout << "\t" << "������ ������� �������������" << std::endl;
			break;
		}
		case 2: {
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