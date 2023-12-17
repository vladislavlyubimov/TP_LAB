#include "KeeperT.h"
#include<iostream>
#include <conio.h>
#include <windows.h>

class Anyof
{
public:
	bool operator()(char* arr, char symbol)
	{
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == symbol) {
				return true;
			}
		}
		return false;
	}
	bool operator()(char symbol, char* arr)
	{
		return anyof(arr, symbol);
	}

	bool operator()(std::string arr, char symbol)
	{
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == symbol) {
				return true;
			}
		}
		return false;
	}
	bool operator()(char symbol, std::string arr)
	{
		return anyof(arr, symbol);
	}
}anyof;

KeeperT::KeeperT()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;

	int phase = 0;

	ifstream fin("1.txt");
	string str = "";
	char separator[] = { '.', '?', '!', '…', '\0' };
	char first_let[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char symbol;
	char prevsym = ' ';

	while (fin.get(symbol))
	{
		switch (phase)
		{
		case 0://Поиск Тире
			if (symbol == 45 && prevsym == 32)
			{
				str += symbol;
				phase = 1;
			}
			break;
		case 1://Поиск заглавной
			if (anyof(first_let, symbol))
			{
				str += symbol;
				phase = 2;
			}
			else
			{
				str = "";
				phase = 0;
			}
			break;
		case 2://Запись предложения
			str += symbol;
			if (anyof(separator, symbol))
			{
				phase = 3;
			}
			break;
		case 3://Поиск пробела
			if (symbol == 32)
			{
				this->push_back(str);
				str = "";
				phase = 0;
			}
			break;
		}
		prevsym = symbol;
	}
}
KeeperT::~KeeperT()
{
	clear();
}


void KeeperT::pop_front()
{
	int si = this->Size;
	if (si)//Фикс исключения 1
	{
		Senten* temp = head;
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
void KeeperT::push_back(string data)
{
	if (head == nullptr)
	{
		head = new Senten(data);
		tail = this->head;
	}
	else
	{
		Senten* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Senten(data, current->pNext, current);
		tail = current->pNext;
	}
	Size++;
}

void KeeperT::clear()
{
	while (Size)
	{
		pop_front();
	}
}


int KeeperT::GetSize()
{
	return Size;
}

int KeeperT::request_strt()
{
	int strt;
	cout << "Input container length: ";
	cin >> strt;
	return strt;
}


string KeeperT::operator[](const int index)
{
	int counter = 0;
	string ret;
	Senten* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			ret = current->gettext();
			return ret;
		}
		current = current->pNext;
		counter++;
	}

}
void KeeperT::Show()
{
	Senten* current = this->head;
	int check = 0;
	
	cout << endl;
	while (current != nullptr)
	{
		cout << current->gettext() << endl;
		current = current->pNext;
		check++;
	}
	if (!check)
		cout << "No sentences alligning with set criterias were found!" << endl;
}
