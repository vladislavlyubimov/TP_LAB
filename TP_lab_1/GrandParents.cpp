#include <iostream>
#include <fstream>
#include <string>
#include "GrandParents.h"
using namespace std;

GrandParents::GrandParents()
{
	cout << "Constructor GrandParents without attributes was called." << endl;
}
GrandParents::~GrandParents()
{
	cout << "Destructor GrandParents was called." << endl;
}
GrandParents::GrandParents(const GrandParents& GrandParents_copy)
{
	fullName = GrandParents_copy.fullName;
	parents = GrandParents_copy.parents;
	spouses = GrandParents_copy.spouses;
	children = GrandParents_copy.children;
	dateBirh = GrandParents_copy.dateBirh;
	dateDeath = GrandParents_copy.dateDeath;
	age = GrandParents_copy.age;
	cout << "Constructor copy was called." << endl;
}
GrandParents::GrandParents(string fullName)
{
	this->fullName = fullName; cout << "Constructor GrandParents with attributes was called." << endl;
}
string GrandParents::get_fullName() const
{
	return fullName;
}
void GrandParents::set_fullName(string name_ch)
{
	fullName = name_ch;
}
string GrandParents::get_parents() const
{
	return parents;
}
void GrandParents::set_parents(string post_ch)
{
	parents = post_ch;
}
string GrandParents::get_spouses() const
{
	return spouses;
}
void GrandParents::set_spouses(string number_ch)
{
	spouses = number_ch;
}
string GrandParents::get_children() const
{
	return children;
}
void GrandParents::set_children(string children_ch)
{
	children = children_ch;
}

string GrandParents::get_dateBirh() const
{
	return dateBirh;
}
void GrandParents::set_dateBirh(string dateBirh_ch)
{
	dateBirh = dateBirh_ch;
}

string GrandParents::get_dateDeath() const
{
	return dateDeath;
}
void GrandParents::set_dateDeath(string dateDeath_ch)
{
	dateDeath = dateDeath_ch;
}

string GrandParents::get_age() const
{
	return age;
}
void GrandParents::set_age(string age_ch)
{
	age = age_ch;
}

void GrandParents::show() {
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
void GrandParents::rewrite()
{
	cout << "------------------------------------" << endl;
	cout << "Person: GrandParents" << endl;
	cout << "Input fullName: ";
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
void GrandParents::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening the outfile << endl!";
		exit(1);
	}
	outfile << 3 << endl << fullName << endl << parents << endl << spouses << endl << children << endl << dateBirh << endl << dateDeath << endl << age << endl;
	outfile.close();
}
void GrandParents::redact_str(int num_str, string red_str) {
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
