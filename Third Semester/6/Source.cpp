#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("out.txt");

struct Node // �������������� ���������
{
	int data; // ������(�����) ����������� � ����
	Node *next; // ��������� �� ��������� ����
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
	Node *head = NULL; // ������ ��������� �� ����, �.�. ������ ����
	head = new Node;  // �������� ������ ��� ������� ������
	fin >> head->data; // ��������� ���� � ������� 
	head->next = NULL;// ��������� �� ��������� ������� ����
	Node *NewHead; //������ ��������������� ����������-���������, ������� ����� ������� ����� ���������� �������� ������
	NewHead = head; // ������ ��������� ������� ������ ��������� � ��� �������
	while (!fin.eof())
	{
		NewHead->next = new Node; // �������� ����� � ������ ��� ���������� �������� ������ � �������������� ��������� newh �� ���������� ������� ������
		NewHead = NewHead->next;
		fin >> NewHead->data;//����� ���������� �������� ����� �������� ������
		NewHead->next = NULL;
	}
	fout << "������ �� �������� ���������� ��������:" << endl;
	print(head);
	fout << endl;
	DeleteLast(head);
	fout << "������ ����� �������� ���������� ��������:" << endl;
	print(head);
	deletelist(head);
	fin.close();
	fout.close();
}