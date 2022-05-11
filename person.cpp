#include "person.h"
#include <ostream>
#include <string>

using namespace std;


Person::Person(string name, unsigned int wealth=0) : name{name}, wealth{wealth} {
	if(name.empty()) throw runtime_error("name cannot be emopty");
}

void Person::work(string guild) {
	if(licenses.count(guild)){
		unique_ptr<License> license = licenses[guild];

		if(license->is_valid()){
			license->use();
			if(!pay_fee(license->get_salary())) throw runtime_error ("cannot pay fee");
		}
	}
	throw runtime_error("no licenses for guild");
}

void Person::increase_weath(unsigned int i) {
	wealth += i;
}

string Person::get_name() {
	return name;
}

bool Person::pay_fee(unsigned int i) {
	if(wealth < i || i <= 0) return false;

	wealth -= i;
	return true;
}

void Person::receive_license(unique_ptr<License> l) {
	licenses[l->get_guildname()] = l;
}

void Person::transfer_license(string l, shared_ptr<Person> p) {
	if(!licenses.count(l)) throw runtime_error("cannot transfer license");

	p->receive_license(licenses[l]);
	licenses.erase(l);
}

bool Person::eligible(string l) const {
	return licenses.count(l) && licenses[l]->is_valid();
}



