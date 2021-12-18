#include <iostream>
#include <string>
#include <vector>

/// <summary>
/// Класс для структуры данных очередь
/// </summary>
class Queue
{
public:
	Queue();  //Конструктор
	~Queue(); //Деструктор
	void push(std::string data); // Добавление элемента в очередь
	int GetSize() { return size; } //Получение количества элементов
	void PrintQueue(); //Распечатка задач очереди
	void pop(); // Удаление элемента
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
	Node* last;
	int size; //Количество  элементов

};

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
/// <summary>
/// Добавление элемента в очередь
/// </summary>
/// <param name="Data">Элемент очереди</param>
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
void Queue::PrintQueue()
{
	if (size != 0) {
		Node* current = head; // Временная переменная для поиска последнего элемента
		for (size_t i = 0; i < GetSize(); i++)
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
/// <summary>
/// Получение случайной задачи
/// </summary>
/// <param name="a">Массив с задачами</param>
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
			for (size_t i = 0; i < rand() % 10; i++)
			{
				queue.push(GetRandomTask(a));
			}

			std::cout << "\t" << "Задачи успешно сгенерированы" << std::endl;
			break;
		}
		case 2: {
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