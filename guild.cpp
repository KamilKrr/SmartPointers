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
  if(name.empty() || fee <= 0 || salary <= 0) throw runtime_error("cannot create guild");
  
	for(const auto& member : members){
  	if(this->members.count(member->get_name())) throw runtime_error("duplicate member");
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
    return;
	}
	throw runtime_error("person cannot pay fee");
}
bool Guild::offer_job(shared_ptr<Person> p) const {
	if(members.count(p->get_name())){
  	p->work(salary * 2);
    return true;
  }else if(p->eligible(name)) {
    p->work(name);
    return true;
  }
  return false;
}


ostream& Guild::print(ostream& o) const {
	o << "[" << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
  bool first = true;
	for(auto member : members){
    if(first) first = false;
    else o << ", ";
    
		o << member.first;
  }
	o << "}]";
	return o;
}

