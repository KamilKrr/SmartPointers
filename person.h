#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>

using namespace std;

class License;

class Person {
	string name;
	unsigned int wealth;
	map<string, unique_ptr<License>> licenses;

public:
	Person(string name, unsigned int wealth=0);
	virtual ~Person() = default;
	void work(string guild);
  virtual void work(unsigned int) = 0;
	void increase_wealth(unsigned int i);
	string get_name() const;
	bool pay_fee(unsigned int i);
	void receive_license(unique_ptr<License> l);
	void transfer_license(string l, shared_ptr<Person> p);
	bool eligible(string l) const;
	virtual	ostream& print(ostream& o) const;

};

inline ostream& operator<< (ostream& o, const Person& p) {
	return p.print(o);
};

class Worker : virtual public Person {
public:
  Worker(string name, unsigned int wealth = 0);
  void work(unsigned int i);
  ostream& print(ostream& o) const;
};

class Superworker : virtual public Person {
  unsigned int fee;
public:
  Superworker(unsigned int fee,string,unsigned int=0);
  void work(unsigned int i);
  ostream& print(ostream& o) const;
};


#endif
