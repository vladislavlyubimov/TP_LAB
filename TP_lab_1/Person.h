#pragma once
using namespace std;
class Person {
public:
	Person() {};
	virtual ~Person() {};

	virtual void show() = 0;
	virtual void rewrite() = 0;
	virtual void saving() = 0;
	virtual void redact_str(int num_str, string red_str) = 0;
};
typedef struct El
{
	Person* data;
	El* next;
} El;
