#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "person.h"
#include "license.h"

using namespace std;


Person::Person(string name, unsigned int wealth) : name{name}, wealth{wealth} {
	if(name.empty()) throw runtime_error("name cannot be emopty");
}

void Person::work(string guild) {
	if(licenses.count(guild)){
		if(licenses.at(guild)->valid()){
      work(licenses.at(guild)->get_salary());
      licenses.at(guild)->use();
      return;
		}
	}
  throw runtime_error("no licenses for guild");
}

void Person::increase_wealth(unsigned int i) {
	wealth += i;
}

string Person::get_name() const {
	return name;
}

bool Person::pay_fee(unsigned int i) {
	if(wealth < i || i <= 0) return false;

	wealth -= i;
	return true;
}

void Person::receive_license(unique_ptr<License> l) {
	licenses[l->get_guildname()] = move(l);
}

void Person::transfer_license(string l, shared_ptr<Person> p) {
	if(!licenses.count(l)) throw runtime_error("cannot transfer license");

	p->receive_license(move(licenses.at(l)));
  licenses.erase(l);
}

bool Person::eligible(string l) const {
	return licenses.count(l) && licenses.at(l)->valid();
}

ostream& Person::print(ostream& o) const {
	o << name << ", " << wealth << " Coins, {";
  for(const auto& license : licenses)
		o << *(license.second);
  o << "}";
return o;
}

Worker::Worker(string name, unsigned int wealth) : Person(name, wealth) {};

void Worker::work(unsigned int i) {
	increase_wealth(i);
}

ostream& Worker::print(ostream& o) const {
	o << "[Worker ";
  Person::print(o);
  o << "]";
	return o;
}

Superworker::Superworker(unsigned int fee, string name, unsigned int wealth) : Person(name, wealth), fee{fee} {};

void Superworker::work(unsigned int i) {
  increase_wealth(i + fee);
}

ostream& Superworker::print(ostream& o) const {
	o << "[Superworker ";
  Person::print(o);
  o << "]";
	return o;
}


