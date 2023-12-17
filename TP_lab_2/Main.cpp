#include "KeeperN.h"
#include "KeeperT.h"

#include <list>
#include <iostream>
#define cles 1
using namespace std;

void menu();
void cls();
void men();
void disp();
void inc();


int main(void)
{
	menu();
	return 0;
}

void menu()
{
	int choice = 0;
	int k = 0;
	int d = 0;
	int filt = 0;
	cls();
	KeeperN bob(0);
	KeeperN aero(bob);
	KeeperT texo;
	k = 0;
	men();
	//вывод в консоль
	while (choice != 3)
	{
		cin >> choice;
		cls();
		switch (choice)
		{
		case 1: //////////////////////////////Open Note
		{
			aero.push_back();
			k = 0;
			cls();
			disp();
			aero.Show();
			while (k != 5)
			{
				cin >> k;
				switch (k)
				{
				case 1:////Add element
					cls();
					disp();
					aero.push_back();
					cls();
					disp();
					aero.Show();
					break;
				case 2://///Remove element
					cls();
					disp();
					cout << "What entry you'd like to remove?" << endl;
					cin >> d;
					aero.pop(d);
					cls();
					disp();
					aero.Show();
					break;

				case 3:///Show all entries
					cls();
					disp();
					aero.setfilt();
					aero.Show();
					break;
				case 4:///Filter
					cls();
					disp();
					cout << "Who would you like to see? (Input their phone number)" << endl;
					cin >> filt;
					aero.setfilt(filt);
					cls();
					disp();
					aero.Show();
					break;
				case 5:///To main menu
					cls();
					men();

					break;
				default:
					cls();
					disp();

					inc();
					break;
				}
			}
			break;
		}
		case 2: //////////////////////////////Output edited text from file
		{
			cls();
			men();
			texo.Show();
			break;
		}
		case 3://////////////////////////////Exit
		{
			cls();
			men();
			break;
		}
		default:
		{
			cls();
			men();

			inc();
			break;
		}
		}
	}
}

void men()
{
	cout << "Menu:\n(1)Note\n(2)Output text from file\n(3)Exit"<< endl;
}

void disp()
{
	cout << "(1)Add element\n(2)Remove element\n(3)Show all people\n(4)Find by phone number\n(5)To menu" << endl << endl;
}

void cls()
{
	if (cles)
		system("cls");
}

void inc()
{
	cout << "Incorrect input!\n" << endl;
}
