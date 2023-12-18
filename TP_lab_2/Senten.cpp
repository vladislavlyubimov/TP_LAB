#include "Senten.h"

void Senten::setdat(int data)
{
	this->data = data;
}

void Senten::settext(string text)
{
	this->text = text;
}

string Senten::gettext()
{
	return this->text;
}

Senten::Senten(string data, Senten* pNext, Senten* pPrev)
{
	this->data = 0;
	this->pNext = pNext;
	this->pPrev = pPrev;
	this->text = data;
}
