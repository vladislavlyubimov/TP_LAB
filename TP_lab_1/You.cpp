#include <iostream>
#include <fstream>
#include <string>
#include "You.h"
using namespace std;

You::You() { cout << "Constructor You without attributes was called." << endl; }
You::~You() { cout << "Destructor You was called." << endl; }
You::You(const You& You_copy) {
	fullName = You_copy.fullName;
	parents = You_copy.parents;
	spouses = You_copy.spouses;
	children = You_copy.children;
	dateBirh = You_copy.dateBirh;
	dateDeath = You_copy.dateDeath;
	age = You_copy.age;
	cout << "Constructor copy You was called." << endl;
}
You::You(string fullName)
{
	this->fullName = fullName; cout << "Constructor You with attributes was called." << endl;
}
string You::get_fullName() const
{
	return fullName;
}
void You::set_fullName(string name_ch)
{
	fullName = name_ch;
}
string You::get_parents() const
{
	return parents;
}
void You::set_parents(string post_ch)
{
	parents = post_ch;
}
string You::get_spouses() const
{
	return spouses;
}
void You::set_spouses(string number_ch)
{
	spouses = number_ch;
}
string You::get_children() const
{
	return children;
}
void You::set_children(string children_ch)
{
	children = children_ch;
}

string You::get_dateBirh() const
{
	return dateBirh;
}
void You::set_dateBirh(string dateBirh_ch)
{
	dateBirh = dateBirh_ch;
}

string You::get_dateDeath() const
{
	return dateDeath;
}
void You::set_dateDeath(string dateDeath_ch)
{
	dateDeath = dateDeath_ch;
}

string You::get_age() const
{
	return age;
}
void You::set_age(string age_ch)
{
	age = age_ch;
}
void You::show() {
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
void You::rewrite()
{
	cout << "------------------------------------" << endl;
	cout << "Person: You" << endl;
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
void You::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening!" << endl;
		exit(1);
	}
	outfile << 4 << endl << fullName << endl << parents << endl << spouses << endl << children << endl << dateBirh << endl << dateDeath << endl << age << endl;
	outfile.close();
}
void You::redact_str(int num_str, string red_str) {
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
		throw "Incorrect number of string!";
		break;
	}
}
