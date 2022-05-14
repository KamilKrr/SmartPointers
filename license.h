#ifndef LICENSE_H
#define LICENSE_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>

using namespace std;

class License {
	string name;
	unsigned int salary;
	unsigned int counter = 0;

public:
	License(string name, unsigned int salary);
	string get_guildname() const;
	unsigned int get_salary() const;
	bool valid() const;
	bool use();
	ostream& print(ostream& o) const;

};

inline ostream& operator<< (ostream& o, const License& l) {
	return l.print(o);
};

#endif
