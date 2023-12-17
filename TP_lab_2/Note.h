#pragma once

#include <iostream>
#include <string>
using namespace std;

class Note
{
public:
	Note* pNext;
	Note* pPrev;
	Note(int data = int(), Note* pNext = nullptr, Note* pPrev = nullptr);
	Note(string temp);

	void setname(string dest="anton");
	void setdat(int dat = 0);
	void setbd(int d = 0, int m = 0, int y = 0);

	string getname();
	int getdat();
	int& getbday();
	
	friend std::istream& operator>>(std::istream& input, Note& no);
	friend std::ostream& operator<<(std::ostream& output, const Note& no);

private:
	string name;
	int data;
	int bday[3];
};