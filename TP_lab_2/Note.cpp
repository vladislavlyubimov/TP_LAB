#include "Note.h"

Note::Note(int data, Note* pNext, Note* pPrev)
{
	this->data = data;
	this->pNext = pNext;
	this->pPrev = pPrev;
	setname();
	setbd();
	cin >> *this;
}

Note::Note(string temp)
{
	this->data = data;
	this->pNext = pNext;
	this->pPrev = pPrev;
	setname();
	setbd();
}

void Note::setname(string name)
{
	this->name = name;
}

void Note::setdat(int dat)
{
	this->data = dat;
}

void Note::setbd(int d, int m, int y)
{
	this->bday[0] = d;
	this->bday[1] = m;
	this->bday[2] = y;
}

string Note::getname()
{
	return this->name;
}

int Note::getdat()
{
	return this->data;
}

int& Note::getbday()
{
	return *this->bday;
}

istream& operator>>(std::istream& input, Note& no)
{
	cin.ignore(32767, '\n');
	string name;
	string surname;

	int day = 99;
	int month = 99;
	int year = -1;
	int num = 0;

	cout << "\nName: ";
	getline(input, name);
	cout << "\nSurname: ";
	getline(input, surname);
	no.setname(name + " " + surname);

	cout << "\nPhone number: ";
	cin >> num;
	no.setdat(num);

	while(day>30 || day<1)
	{
		cout << "\nDay of birth: ";
		cin >> day;
	}
	while(month>12 || month<1)
	{
		cout << "\nMonth of birth: ";
		cin >> month;
	}
	while (year < 0)
	{
		cout << "\nYear of birth: ";
		cin >> year;
	}
	
	no.setbd(day, month, year);

	return input;
}

ostream& operator<<(ostream& output, const Note& no)
{
	output << "Name: " << no.name << endl<<"Phone number: "<<no.data << endl <<"Birtday: " << no.bday[0] << "-" << no.bday[1] << "-" << no.bday[2] << endl << endl;
	
	return output;
}
