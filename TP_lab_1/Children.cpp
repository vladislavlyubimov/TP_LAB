#include <iostream>
#include <fstream>
#include <string>
#include "Children.h"
using namespace std;

Children::Children() { cout << "Constructor Children without attributes was called." << endl; }
Children::~Children() { cout << "Destructor Children was called." << endl; }
Children::Children(const Children& Children_copy) {
	fullName = Children_copy.fullName;
	parents = Children_copy.parents;
	spouses = Children_copy.spouses;
	children = Children_copy.children;
	dateBirh = Children_copy.dateBirh;
	dateDeath = Children_copy.dateDeath;
	age = Children_copy.age;
	cout << "Constructor copy Children was called." << endl;
}
Children::Children(string fullName)
{
	this->fullName = fullName; cout << "Constructor Children with attributes was called." << endl;
}
string Children::get_fullName() const
{
	return fullName;
}
void Children::set_fullName(string name_ch)
{
	fullName = name_ch;
}
string Children::get_parents() const
{
	return parents;
}
void Children::set_parents(string post_ch)
{
	parents = post_ch;
}
string Children::get_spouses() const
{
	return spouses;
}
void Children::set_spouses(string number_ch)
{
	spouses = number_ch;
}
string Children::get_children() const
{
	return children;
}
void Children::set_children(string children_ch)
{
	children = children_ch;
}

string Children::get_dateBirh() const
{
	return dateBirh;
}
void Children::set_dateBirh(string dateBirh_ch)
{
	dateBirh = dateBirh_ch;
}

string Children::get_dateDeath() const
{
	return dateDeath;
}
void Children::set_dateDeath(string dateDeath_ch)
{
	dateDeath = dateDeath_ch;
}

string Children::get_age() const
{
	return age;
}
void Children::set_age(string age_ch)
{
	age = age_ch;
}
void Children::show() {
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
void Children::rewrite()
{
	cout << "------------------------------------" << endl;
	cout << "Person: Children" << endl;
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
void Children::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening!" << endl;
		exit(1);
	}
	outfile << 1 << endl << fullName << endl << parents << endl << spouses << endl << children << endl << dateBirh << endl << dateDeath << endl << age << endl;
	outfile.close();
}
void Children::redact_str(int num_str, string red_str) {
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
