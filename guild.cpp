#include "guild.h"
#include <ostream>
#include <string>

using namespace std;

Guild::Guild(string name, unsigned int fee, unsigned int sal, const vector<shared_ptr<Person>>& members = {}) : name{name}, fee{fee}, sal{sal}, members{members} {};


bool Guild::add_member(shared_ptr<person> p) {
	if(members.count(p->get_name())
		return false;
	members.insert({p->get_name(), p});
	return true;
}	
bool Guild::remove_member(string n) {
	if(!members.count(p->get_name())
		return false;
	members.erase(p->get_name());
	return true;
}
void Guild::grant_license(string n) {
	if(!m.count(n)) throw runtime_error("person not in guild");
	if(members[n].pay_fee(fee)){
		members[n].receive_license(unique_ptr<License>);
	}
	throw runtime_error("person cannot pay fee");
}
bool Guild::offer_job(shared_ptr<Person> p) const {

}


ostream& Guild::print(ostream& o) const {
	o << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
	for(auto member : members)
		o << member.get_name();
	o << "}]";
	return o;
}


