#ifndef PERSON_H
#define PERSON_H

#include<string>
#include<ostream>
#include<map>
using namespace std;


class Person {
	string name;
	unsigned int wealth;
	map<string, unique_ptr<License>> licenses;

public:
	Person(string name, unsigned int wealth=0);
	virtual ~Person() = default;
	void work(string guild);
	void increase_weath(unsigned int i);
	string get_name() const;
	bool pay_fee(unsigned int i);
	void receive_license(unique_ptr<License> l);
	void transfer_license(string l, shared_ptr<Person> p);
	bool eligible(string l) const;
	virtual	ostream& print(ostream& o) const;

};

inline ostream& operator<< (ostream& o, const Guild& g) {
	return g.print(o);
};

#endif
