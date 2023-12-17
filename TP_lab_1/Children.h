#pragma once
#include "Person.h"
using namespace std;
class Children : public Person {
private:
	string fullName;
	string parents;
	string spouses;
	string children;
	string dateBirh;
	string dateDeath;
	string age;
public:
	Children();
	~Children();
	Children(const Children& Children_copy);
	Children(string fullName);

	string get_fullName() const;
	void set_fullName(string fullName_ch);

	string get_parents() const;
	void set_parents(string parents_ch);

	string get_spouses() const;
	void set_spouses(string spouses_ch);

	string get_children() const;
	void set_children(string children_ch);

	string get_dateBirh() const;
	void set_dateBirh(string dateBirh_ch);

	string get_dateDeath() const;
	void set_dateDeath(string dateDeath_ch);

	string get_age() const;
	void set_age(string age_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
};
