#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include<map>
#include "guild.h"
#include "license.h"
#include "person.h"

using namespace std;

Guild::Guild(string name, unsigned int fee, unsigned int salary, const vector<shared_ptr<Person>>& members) : name{name}, fee{fee}, salary{salary} {
	for(const auto& member : members){
  	 this->members[member->get_name()] = member;
  }
};


bool Guild::add_member(shared_ptr<Person> p) {
	if(members.count(p->get_name()))
		return false;
	members.insert({p->get_name(), p});
	return true;
}	
bool Guild::remove_member(string n) {
	if(!members.count(n))
		return false;
	members.erase(n);
	return true;
}
void Guild::grant_license(string n) {
	if(!members.count(n)) throw runtime_error("person not in guild");
	if(members[n]->pay_fee(fee)){
		members[n]->receive_license(make_unique<License>(name, salary));
	}
	throw runtime_error("person cannot pay fee");
}
bool Guild::offer_job(shared_ptr<Person> p) const {
	if(members.count(p->get_name())){
  	p->work(salary * 2);
  }else if(p->eligible(name)) {
    p->work(salary);
  }
  return false;
}


ostream& Guild::print(ostream& o) const {
	o << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
	for(auto member : members)
		o << member.first;
	o << "}]";
	return o;
}


