#include "person.h"
#include <ostream>
#include <string>

using namespace std;


Person::Person(string name, unsigned int wealth=0) : name{name}, wealth{wealth} {
	if(name.empty()) throw runtime_error("name cannot be emopty");
};

void Person::work(string guild) {
	
};



