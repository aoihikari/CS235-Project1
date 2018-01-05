#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
//---------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------
class Student
{
private:
	string id;
	string name;
	string address;
	string phone;
	
public:
	Student(string _id);
	string to_string() ;
	string get_id() const {return id;}
	string get_name() const {return name;}
	string get_address() const {return address;}
	string get_phone() const {return phone;}
	void set_name(string _name) {name = _name;}
	void set_address(string _address) {address = _address;}
	void set_phone(string _phone) {phone = _phone;}	
	bool operator< (Student s) const {return id < s.id;}
	~Student();
};
//---------------------------------------------------------------------------------------

