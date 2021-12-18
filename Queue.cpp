#include "Queue.h"
/// <summary>
/// Конструктор
/// </summary>
Queue::Queue()
{
	size = 0;
	head = nullptr;
	last = nullptr;
}
/// <summary>
/// Деструктор
/// </summary>
Queue::~Queue()
{
	Clear();
}
void Queue::push(std::string data)
{
	if (head == nullptr)  //Проверка, создан ли первый элемент
	{
		head = new Node(data); // Создание первого элемента, в случае его отсутствия
		last = head;
	}
	else
	{
		last->next = new Node(data); // Создание нового элемента 
		last = last->next;
	}


	size++;

}
/// <summary>
/// Распечатка задач на консоль
/// </summary>
/// <param name="a"></param>
void Queue::PrintTasks()
{
	if (size != 0) {
		Node* current = head; // Временная переменная для поиска последнего элемента
		for (auto i = 0; i < GetSize(); i++)
		{
			std::cout << "\t" << current->data << std::endl; //Вывод информации из поля Data
			current = current->next; // Переход к следующему элементу очереди
		}
	}



}
/// <summary>
/// Исключение первого элемента
/// </summary>
void Queue::pop()
{
	if (size > 0) {
		Node* temp = head; // Временная переменная 
		head = head->next; // Переход к следующему элементу
		delete temp; // Удаление
		size--;

	}
}
/// <summary>
/// Очистка очереди
/// </summary>
void Queue::Clear()
{
	while (size)
	{
		pop();
	}
}