#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
//---------------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------------
class Grade
{
private:
	string id;
	string course;
	string grade;
		
public:
	Grade(string _id);
	string to_string() ;
	string get_id() const {return id;}
	string get_course() const {return course;}
	string get_grade() const {return grade;}
	void set_course(string _course) {course = _course;}
	void set_grade(string _grade) {grade = _grade;}
	bool operator< (Grade g) const {return id < g.id || (id == g.id && course < g.course) || (id == g.id && course == g.course && grade < g.grade);
  }
	~Grade();
};
//---------------------------------------------------------------------------------------

