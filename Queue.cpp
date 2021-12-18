#include "Queue.h"
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
void Queue::PrintTasks()
{
	if (size != 0) {
		Node* current = head; // ��������� ���������� ��� ������ ���������� ��������
		for (auto i = 0; i < GetSize(); i++)
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