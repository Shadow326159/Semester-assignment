#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("out.txt");

struct Node // Инициализируем структуру
{
	int data; // Данные(число) записываемы в узел
	Node *next; // Указатель на следующий узел
};

void DeleteLast(Node *head)
{
	Node *Reading;
	if (head == NULL) return;
	for (Reading = head; Reading->next->next; Reading = Reading->next);
	delete Reading->next;
	Reading->next = NULL;
}

void print(Node *head)
{
	Node *newh = head;
	while (newh != NULL)
	{
		fout << newh->data << endl;
		newh = newh->next;
	}
}

void deletelist(Node *head)
{
	Node *temp;
	while (head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Node *head = NULL; // Голова указывает на ноль, т.е. список пуст
	head = new Node;  // Выделяем память под элемент списка
	fin >> head->data; // Заполняем поле с данными 
	head->next = NULL;// Указатель на следующий элемент пуст
	Node *NewHead; //Заведём вспомогательную переменную-указатель, которая будет хранить адрес последнего элемента списка
	NewHead = head; // Сейчас последний элемент списка совпадает с его началом
	while (!fin.eof())
	{
		NewHead->next = new Node; // Выделяем место в памяти для следующего элемента списка и перенаправляем указатель newh на выделенную область памяти
		NewHead = NewHead->next;
		fin >> NewHead->data;//Затем определяем значение этого элемента списка
		NewHead->next = NULL;
	}
	fout << "Список до удаления последнего элемента:" << endl;
	print(head);
	fout << endl;
	DeleteLast(head);
	fout << "Список после удаления последнего элемента:" << endl;
	print(head);
	deletelist(head);
	fin.close();
	fout.close();
}