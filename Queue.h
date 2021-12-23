#pragma once
#include <iostream>
#include <string>
/// <summary>
/// ����� ��� ��������� ������ �������
/// </summary>
class Queue
{
public:
	Queue();  //�����������
	~Queue(); //����������
	void AddTask(std::string data); // ���������� �������� � �������
	int GetSize() { return size; } //��������� ���������� ���������
	void PrintTasks(); //���������� ����� �������
	void DeleteTask(); // �������� ��������
	bool Empty(); //�������� �� �������
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
	Node* last; // ����� ������
	int size; //����������  ���������


};

