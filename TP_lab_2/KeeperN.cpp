#include "KeeperN.h"
#include<iostream>
#include <conio.h>
#include <windows.h>

KeeperN::KeeperN()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
	filter = 0;
}

KeeperN::KeeperN(int siz)
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
	filter = 0;
	Spawn(siz);
}

KeeperN::~KeeperN()
{
	clear();
}

KeeperN::KeeperN(const KeeperN& other)
{
	int cnt = 0;
	this->Size = other.Size;

	Note* current = nullptr;
	Note* current1 = nullptr;
	this->head = current;
	filter = 0;


	for (cnt = 0; cnt < this->Size; cnt++)
	{
		if (head == nullptr)
		{
			this->head = new Note(other.head->getdat());
			this->tail = this->head;
		}
		else
		{
			current = other.head;
			current1 = this->head;

			while (current1->pNext != nullptr)
			{
				current = current->pNext;
				current1 = current1->pNext;
			}
			current1->pNext = new Note(current->pNext->getdat(), current1->pNext, current1);
			this->tail = current1->pNext;
		}
	}
}

void KeeperN::swap(int fir, int sec)
{
	Note* first = this->head;
	Note* second = this->head;
	int cntf = 0;
	int cnts = 0;
	int d = 0, m = 0, y = 0;
	int* arr;

	while (first != nullptr)
	{
		if (cntf == fir)
		{
			break;
		}
		first = first->pNext;
		cntf++;
	}
	while (second != nullptr)
	{
		if (cnts == sec)
		{
			break;
		}
		second = second->pNext;
		cnts++;
	}

	Note* temp = new Note("temp");

	temp->setname(first->getname());
	temp->setdat(first->getdat());
	arr = &first->getbday();
	d = arr[0];
	m = arr[1];
	y = arr[2];
	temp->setbd(d, m, y);

	first->setname(second->getname());
	first->setdat(second->getdat());
	arr = &second->getbday();
	d = arr[0];
	m = arr[1];
	y = arr[2];
	first->setbd(d, m, y);

	second->setname(temp->getname());
	second->setdat(temp->getdat());
	arr = &temp->getbday();
	d = arr[0];
	m = arr[1];
	y = arr[2];
	second->setbd(d, m, y);

	
	delete temp;
}

void KeeperN::sort()
{
	int i, j;
	Note* fir = this->head;
	Note* sec = fir->pNext;
	int* first;
	int* second;
	int dat1;
	int dat2;

	for (i = 0; i < Size - 1; i++)
	{
		fir = this->head;
		sec = fir->pNext;
		for (j = 0; j < Size - i - 1; j++)
		{
			first = &fir->getbday();
			second = &sec->getbday();
			dat1 = first[1] * 30 + first[0];
			dat2 = second[1] * 30 + second[0];

			if ((dat1 > dat2))
				this->swap(j, j + 1);
			fir = fir->pNext;
			sec = fir->pNext;
		}
	}
}

void KeeperN::pop_front()
{
	int si = this->Size;
	if (si)//Фикс исключения 1
	{
		Note* temp = head;
		head = head->pNext;//Исключение 1: попытка чтения поля пустого элемента
		delete temp;
		Size--;
	}
	else
	{
		cout << "Bad Input: cannot delete an element of an empty container" << endl;
		Sleep(1000);
	}
}

void KeeperN::pop_back()
{
	int si = this->Size;
	if (si)//Фикс исключения 2
	{
		Note* temp = tail;
		tail = tail->pPrev;//Исключение 2: попытка чтения поля пустого элемента
		if (si > 1)
		{
			tail->pNext = nullptr;
			delete temp;
			Size--;
		}
		else
		{
			this->head = nullptr;
			this->Size = 0;
		}
	}
	else
	{
		cout << "Bad Input: cannot delete an element of an empty container" << endl;
		Sleep(1000);
	}
}

void KeeperN::pop(int d)
{
	int si = this->Size;
	int i = 0;

	if (d<0 || d>si - 1)
	{
		cout << "Incorrect range!" << endl;
		Sleep(1000);
	}
	else if (d == 0)
		this->pop_front();
	else if (d == si - 1)
		this->pop_back();
	else
	{
		Note* temp = this->head;
		Note* tem1 = nullptr;
		while (i != d)
		{
			tem1 = temp;
			temp = temp->pNext;
			temp->pPrev = tem1;
			i++;
		}
		temp->pPrev->pNext = temp->pNext;
		temp->pNext->pPrev = temp->pPrev;
		delete temp;
		Size--;
	}

}

void KeeperN::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Note(data);
		tail = this->head;
	}
	else
	{
		Note* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Note(data, current->pNext, current);
		tail = current->pNext;
	}
	Size++;
}

void KeeperN::clear()
{
	while (Size)
	{
		pop_front();
	}
}

void KeeperN::setfilt(int filter)
{
	this->filter = filter;
}


int KeeperN::GetSize()
{
	return Size;
}

int KeeperN::request_strt()
{
	int strt;
	cout << "Input container length: ";
	cin >> strt;
	return strt;
}

void KeeperN::Spawn()
{
	int strt = request_strt();
	for (int i = 0; i < strt; i++)
	{
		push_back(rand() % 100);
	}
}

void KeeperN::Spawn(int siz)
{
	int strt = siz;
	for (int i = 0; i < strt; i++)
	{
		push_back(rand() % 100);
	}
}

string KeeperN::operator[](const int index)
{
	int counter = 0;
	string ret;
	Note* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			ret = current->getname();
			return ret;
		}
		current = current->pNext;
		counter++;
	}

}

void KeeperN::test()
{
	Note* current = this->head;
	int *a = &current->getbday();
	cout << a[0] << " " << a[1] << " " << a[2] << " " << endl;
}

void KeeperN::Show()
{
	if (filter == 0)
		cout << "Currently showing all entries" << endl << endl;
	else
		cout << "Currently showing entry with the following phone number: "<< filter << endl << endl;
	Note* current = this->head;
	int cur_num;
	this->sort();
	int check = 0;
	if (current != nullptr)
	{
		while (current->pNext != nullptr)
		{
			cur_num = current->getdat();
			if (filter != 0 && cur_num == filter)
			{
				cout << *current;
				check++;
			}
			else if (filter == 0)
				cout << *current;
			
			current = current->pNext;
		}
		cur_num = current->getdat();
		if (filter != 0 && cur_num == filter)
		{
			cout << *current;
			check++;
		}
		else if (filter == 0)
			cout << *current;

		if (!check && filter != 0)
			cout << "No entries with the following number were found!" << endl;
	}
	else
		cout << "The list is empty!!!" << endl;
}

