#pragma once

#include "Note.h"
#include <iostream>
#include <string>
using namespace std;


class KeeperN
{
public:
	KeeperN();
	explicit KeeperN(int siz);
	~KeeperN();
	KeeperN(const KeeperN& other);
	void swap(int fir, int sec);
	void sort();
	void pop_front();
	void pop_back();
	void pop(int d);
	void push_back(int data = rand() % 1000);
	void clear();
	void setfilt(int filter = 0);
	int GetSize();
	int request_strt();
	void Spawn();
	void Spawn(int siz);
	string operator[](int index);
	void test();
	void Show();
private:
	int Size;
	int filter;
	Note* head;
	Note* tail;
};
