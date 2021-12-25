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
	clear();
}

/// <summary>
/// ���������� ��������
/// </summary>
/// <param name="data"></param>
void Queue::Add(std::string data)
{
	if (Empty())  //��������, ������ �� ������ �������
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
void Queue::print()
{
	if (Empty() == false) {
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
void Queue::Delete()
{
	if (Empty() == false) {
		Node* temp = head; // ��������� ���������� 
		head = head->next; // ������� � ���������� ��������
		delete temp; // ��������
		size--;

	}
}
/// <summary>
/// �������� �� �������
/// </summary>
/// <returns></returns>
bool Queue::Empty()
{	
	return size == 0;
}
/// <summary>
/// ������� �������
/// </summary>
void Queue::clear()
{
	while (Empty() == false)
	{
		Delete();
	}
}
