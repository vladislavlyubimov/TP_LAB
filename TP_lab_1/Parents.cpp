#include <iostream>
#include <fstream>
#include <string>
#include "Parents.h"
using namespace std;

Parents::Parents()
{
	cout << "Constructor Parents without attributes was called." << endl;
}
Parents::~Parents() { cout << "Destructor Parents was called." << endl; }
Parents::Parents(const Parents& Parents_copy) {
	fullName = Parents_copy.fullName;
	parents = Parents_copy.parents;
	spouses = Parents_copy.spouses;
	children = Parents_copy.children;
	dateBirh = Parents_copy.dateBirh;
	dateDeath = Parents_copy.dateDeath;
	age = Parents_copy.age;
	cout << "Constructor copy Parents was called." << endl;
}
Parents::Parents(string fullName)
{
	this->fullName = fullName; cout << "Constructor Parents with attributes was called." << endl;
}
string Parents::get_fullName() const
{
	return fullName;
}
void Parents::set_fullName(string name_ch)
{
	fullName = name_ch;
}
string Parents::get_parents() const
{
	return parents;
}
void Parents::set_parents(string post_ch)
{
	parents = post_ch;
}
string Parents::get_spouses() const
{
	return spouses;
}
void Parents::set_spouses(string number_ch)
{
	spouses = number_ch;
}
string Parents::get_children() const
{
	return children;
}
void Parents::set_children(string children_ch)
{
	children = children_ch;
}

string Parents::get_dateBirh() const
{
	return dateBirh;
}
void Parents::set_dateBirh(string dateBirh_ch)
{
	dateBirh = dateBirh_ch;
}

string Parents::get_dateDeath() const
{
	return dateDeath;
}
void Parents::set_dateDeath(string dateDeath_ch)
{
	dateDeath = dateDeath_ch;
}

string Parents::get_age() const
{
	return age;
}
void Parents::set_age(string age_ch)
{
	age = age_ch;
}
void Parents::show() {
	cout << "------------------------------------" << endl;
	cout << "Person: You" << endl;
	cout << "Full Name: " << fullName << endl;
	cout << "Parents: " << parents << endl;
	cout << "Spouses: " << spouses << endl;
	cout << "Children: " << children << endl;
	cout << "Birhday: " << dateBirh << endl;
	cout << "Death Date: " << dateDeath << endl;
	cout << "Age: " << age << endl;
	cout << "------------------------------------" << endl;
}
void Parents::rewrite() {
	cout << "------------------------------------" << endl;
	cout << "Parents: " << endl;
	cout << "Input new fullName: ";
	getline(cin, fullName);
	getline(cin, fullName);
	cout << "Input parents: ";
	getline(cin, parents);
	cout << "Input spouses: ";
	getline(cin, spouses);
	cout << "Input children: ";
	getline(cin, children);
	cout << "Input date birhday: ";
	getline(cin, dateBirh);
	cout << "Input date death: ";
	getline(cin, dateDeath);
	cout << "Input age: ";
	getline(cin, age);
	cout << "------------------------------------" << endl;
}
void Parents::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening the outfile!" << endl;
		exit(1);
	}
	else
	{
		outfile << 2 << endl << fullName << endl << parents << endl << spouses << endl << children << endl << dateBirh << endl << dateDeath << endl << age << endl;
		outfile.close();
	}
}
void Parents::redact_str(int num_str, string red_str) {
	switch (num_str)
	{
	case 1:
		this->fullName = red_str;
		break;
	case 2:
		this->parents = red_str;
		break;
	case 3:
		this->spouses = red_str;
		break;
	case 4:
		this->children = red_str;
		break;
	case 5:
		this->dateBirh = red_str;
		break;
	case 6:
		this->dateDeath = red_str;
		break;
	case 7:
		this->age = red_str;
		break;
	default:
		cout << "Incorrect number of string!" << endl;
		break;
	}
}
