#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"

using namespace std;


License::License (string name, unsigned int salary) : name{name}, salary{salary} {
	if(name.empty()) throw new runtime_error("name cannot be empty");
	if(salary == 0) throw new runtime_error("salary must be > 0");
};

string License::get_guildname() const {
	return name;
}

unsigned int License::get_salary() const {
	return salary;
}

bool License::valid() const {
	return counter < 4;
}

bool License::use() {
	if(!valid())
		return false;
	++counter;
	return true;
}

ostream& License::print(ostream& o) const {
	o << "[License for " << name << ", Salary: " << salary << ", Used: " << counter << "]";
return o;
}

