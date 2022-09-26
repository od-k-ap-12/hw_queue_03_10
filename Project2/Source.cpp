#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	// �������
	int* Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	Queue(int m);

	//����������
	~Queue();

	// ���������� ��������
	void Add(int c);

	// ���������� ��������
	int Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();

	int GetFirstWaitingOne();
};

void Queue::Show() {
	cout << "\n-----------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout <<"  "<< Wait[i] << " ";
	}
	cout << "\n-----------------------\n";
}

int Queue::GetFirstWaitingOne()
{
	return Wait[0];
}

Queue::~Queue()
{
	//�������� �������
	delete[]Wait;
}

Queue::Queue(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;
}

void Queue::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;
}
void Queue::Add(int c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull())
		Wait[QueueLength++] = c;
}

int Queue::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������	
	if (!IsEmpty()) {
		//��������� ������
		int temp = Wait[0];

		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++) {
			Wait[i - 1] = Wait[i];
		}
		Wait[QueueLength - 1] = temp;
		//������� ������(�������)
		return temp;
	}

	else // ���� � ����� ��������� ���
		return -1;
}

int main()
{
	srand(time(0));

	Queue QU1(10);
	Queue QU2(10);
	Queue QU3(10);

	for (int i = 1; i < 6; i++) {
		QU1.Add(i);
		QU2.Add(i);
		QU3.Add(i);
	}

	QU1.Show();
	cout << endl;
	QU2.Show();
	cout << endl;
	QU3.Show();

	for (int j = 0; j < rand() % 50; j++) {
		QU1.Extract();
	}
	for (int j = 0; j < rand() % 50; j++) {
		QU2.Extract();
	}
	for (int j = 0; j < rand() % 50; j++) {
		QU3.Extract();
	}
	cout << "------- Results -------" << endl;
	QU1.Show();
	cout << endl;
	QU2.Show();
	cout << endl;
	QU3.Show();
	if (QU1.GetFirstWaitingOne() == QU2.GetFirstWaitingOne() == QU3.GetFirstWaitingOne()) {
		cout << "You won!";
	}
	else {
		cout << "----- You lost :( -----";
	}
}
