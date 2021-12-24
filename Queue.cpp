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
	clear();
}

/// <summary>
/// Добавление элемента
/// </summary>
/// <param name="data"></param>
void Queue::Add(std::string data)
{
	if (Empty())  //Проверка, создан ли первый элемент
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
void Queue::print()
{
	if (Empty() == false) {
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
void Queue::Delete()
{
	if (Empty() == false) {
		Node* temp = head; // Временная переменная 
		head = head->next; // Переход к следующему элементу
		delete temp; // Удаление
		size--;

	}
}
/// <summary>
/// Проверка на пустоту
/// </summary>
/// <returns></returns>
bool Queue::Empty()
{	
	return size == 0;
}
/// <summary>
/// Очистка очереди
/// </summary>
void Queue::clear()
{
	while (Empty() == false)
	{
		Delete();
	}
}
