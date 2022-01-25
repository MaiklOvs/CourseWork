#pragma once
#include <iostream>
#include <string>
/// <summary>
/// Класс для структуры данных очередь
/// </summary>
class Queue
{
public:
	Queue();  //Конструктор
	~Queue(); //Деструктор
	void Add(std::string data); // Добавление элемента в очередь
	int GetSize() { return size; } //Получение количества элементов
	void print(); //Распечатка задач очереди
	void Delete(); // Удаление элемента
	bool Empty(); //Проверка на пустоту
	void Clear();//Очистка очереди
private:
	/// <summary>
	/// Узел списка
	/// </summary>
	class Node //Элемент очереди
	{
	public:
		Node* next; // Указатель на следующий элемент очереди
		std::string data; // Данные, которые хранит элемент очереди
		Node(std::string data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node* head; //Голова списка
	Node* last; // Конец списка
	int size; //Количество  элементов


};

