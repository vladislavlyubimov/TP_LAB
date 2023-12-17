#pragma once
#include <iostream>
#include <string>
#include "Senten.h"
using namespace std;


class KeeperT
{
public:
	KeeperT();
	~KeeperT();
	void pop_front();
	void push_back(string data);
	void clear();
	int GetSize();
	int request_strt();
	string operator[](const int index);
	void Show();
private:
	int Size;
	Senten* head;
	Senten* tail;
};
