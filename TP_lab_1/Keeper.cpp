#include <iostream>
#include <fstream>
#include <string>
#include "Keeper.h"
#include "Children.h"
#include "Parents.h"
#include "GrandParents.h"
#include "You.h"
using namespace std;
Keeper::Keeper() : size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) { this->size = size; }
Keeper::~Keeper() {
	if (head != NULL)
	{
		El* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Person();
			delete(buffer);
		}
		head->data->~Person();
		delete(head);
	}
}
Person* Keeper::operator[] (const int id) {
	if ((id >= size) || id < 0)
	{
		cout << "Incorrect index!" << endl;
		exit(1);
	}
	else
	{
		El* buffer = head;
		for (int i = 0; i < size - id - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->data);
	}
}

int Keeper::get_size() { return size; }

void Keeper::insert(Person* new_data) {
	El* tmp;
	tmp = new El;
	if (size == 0)
	{
		tmp->data = new_data;
		tmp->next = 0;
		++size;
	}
	else
	{
		tmp->data = new_data;
		tmp->next = head;
		++size;
	}
	head = tmp;
}
void Keeper::remove(int id) {
	if ((head != NULL) && (id < size) && (id >= 0))
	{
		El* temp = head, * temp2 = head;
		for (int i = 0; i < id; i++)
		{
			temp2 = temp;
			temp = temp->next;
		}
		if (temp == head)
		{
			head = temp->next;
		}
		else
		{
			temp2->next = temp->next;
		}
		temp->data->~Person();
		delete(temp);
		size--;
	}
}
void Keeper::save() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile.is_open())
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	else
	{
		outfile << size << endl;
		outfile.close();
	}
	El* buffer = head;
	for (int i = 0; i < size; i++)
	{
		buffer->data->saving();
		buffer = buffer->next;
	}
}
void Keeper::load() {
	if (size != 0)
	{
		El* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Person();
			delete(buffer);
		}
		head->data->~Person();
		delete(head);
	}
	ifstream infile;
	int read_size, num_person;
	string a, b, c, d, e, f, g;
	string initfile = "data.txt";
	Person* persons;
	infile.open(initfile);
	if (!infile.is_open())
	{
		cout << "Error opening!" << endl;
		exit(1);
	}
	infile >> read_size;
	for (int i = 0; i < read_size; i++)
	{
		infile >> num_person;
		infile.ignore(32767, '\n');
		if (num_person == 1)
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			getline(infile, g);
			Children* children;
			children = new Children;
			children->set_fullName(a);
			children->set_parents(b);
			children->set_spouses(c);
			children->set_children(d);
			children->set_dateBirh(e);
			children->set_dateDeath(f);
			children->set_age(g);
			persons = children;
			insert(persons);
		}
		if (num_person == 2)
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			getline(infile, g);
			Parents* parents;
			parents = new Parents;
			parents->set_fullName(a);
			parents->set_parents(b);
			parents->set_spouses(c);
			parents->set_children(d);
			parents->set_dateBirh(e);
			parents->set_dateDeath(f);
			parents->set_age(g);
			persons = parents;
			insert(persons);
		}
		if (num_person == 3)
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			getline(infile, g);
			GrandParents* grandPar;
			grandPar = new GrandParents;
			grandPar->set_fullName(a);
			grandPar->set_parents(b);
			grandPar->set_spouses(c);
			grandPar->set_children(d);
			grandPar->set_dateBirh(e);
			grandPar->set_dateDeath(f);
			grandPar->set_age(g);
			persons = grandPar;
			insert(persons);
		}
		if (num_person == 4)
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			getline(infile, g);
			You* you;
			you = new You;
			you->set_fullName(a);
			you->set_parents(b);
			you->set_spouses(c);
			you->set_children(d);
			you->set_dateBirh(e);
			you->set_dateDeath(f);
			you->set_age(g);
			persons = you;
			insert(persons);
		}
	}
}
