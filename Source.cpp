#include "Student.h"
#include "Grade.h"
#include <fstream>
#include <algorithm>
#include <vector>

const double A = 4.0;
const double AM = 3.7;
const double BP = 3.4;
const double B = 3.0;
const double BM = 2.7;
const double CP = 2.4;
const double C = 2.0;
const double CM = 1.7;
const double DP = 1.4;
const double D = 1.0;
const double DM = 0.7;
const double E = 0.0;

void student(ifstream &in_file,vector<Student> &students, int &bad){

string id;
string name;
string address;
string phone;

if (in_file.fail())
	{
		cout << "\nCouldn't load file\n\n" << endl;
		bad = 0;
	}
	else{

		int spot = 0;
		

		while (getline(in_file, id))
		{
			students.push_back(Student(id));			
			getline(in_file, name);
			students[spot].set_name(name);
			getline(in_file, address);
			students[spot].set_address(address);
			getline(in_file, phone);
			students[spot].set_phone(phone);
			spot++;		
		}
		in_file.close();
		sort(students.begin(), students.end());
	}
}

void grade(ifstream &in_file,vector<Grade> &grades, int &bad){

string id;
string course;
string grade;

if (in_file.fail())
	{
		cout << "\nCouldn't load file\n\n" << endl;
		bad = 0;
	}
	else{
		
		int spot = 0;
		
		while (getline(in_file, course))
		{
			getline(in_file, id);
			grades.push_back(Grade(id));
			grades[spot].set_course(course);
			getline(in_file, grade);
			grades[spot].set_grade(grade);
			spot++;		
		}

		in_file.close();
		sort(grades.begin(), grades.end());
	}
}

void gpa_num2(size_t &spot2, double &gpa, vector<Grade> &grades){

if (grades[spot2].get_grade() == "C-")
	{gpa = gpa + CM;}
else if (grades[spot2].get_grade() == "D+")
	{gpa = gpa + DP;}
else if (grades[spot2].get_grade() == "D")
	{gpa = gpa + D;}
else if (grades[spot2].get_grade() == "D-")
	{gpa = gpa + DM;}
else 
	{gpa = gpa + E;}
}

void gpa_num1(size_t &spot2, double &gpa, vector<Grade> &grades){

if (grades[spot2].get_grade() == "A")
	{gpa = gpa + A;}
else if (grades[spot2].get_grade() == "A-")
	{gpa = gpa + AM;}
else if (grades[spot2].get_grade() == "B+")
	{gpa = gpa + BP;}
else if (grades[spot2].get_grade() == "B")
	{gpa = gpa + B;}
else if (grades[spot2].get_grade() == "B-")
	{gpa = gpa + BM;}
else if (grades[spot2].get_grade() == "C+")
	{gpa = gpa + CP;}
else if (grades[spot2].get_grade() == "C")
	{gpa = gpa + C;}
else 
{ gpa_num2(spot2, gpa, grades);}
}

void gpac(vector<string> &query, vector<Student> &students, vector<Grade> &grades, ofstream &out_file){

double gpa = 0;
int counter = 0;

for (size_t spot = 0; spot < query.size(); spot++)
		{
			for (size_t spot1 = 0; spot1 < students.size(); spot1++)
			{
				if (query[spot] == students[spot1].get_id())
				{
					out_file <<	query[spot] << "\t";
					
					for (size_t spot2 = 0; spot2 < grades.size(); spot2++)
					{
						if (query[spot] == grades[spot2].get_id())
						{
							gpa_num1(spot2, gpa, grades);
							counter++;
						} 
					}					
					if (counter == 0){
					
						out_file << fixed << setprecision(2) << setfill('0') << gpa << "\t" << students[spot1].get_name() << endl;
					}
					else{

						out_file << fixed << setprecision(2) << setfill('0') << gpa/counter << "\t" << students[spot1].get_name() << endl;
					}
					gpa = 0;
					counter = 0;
				} 
			}
		}
}

void queryf(ifstream &in_file,vector<string> &query, int &bad, vector<Student> &students, vector<Grade> &grades, ofstream &out_file){

string id;


if (in_file.fail())
	{
		cout << "\nCouldn't load file\n\n" << endl;
		bad = 0;
	}
	else{
		
		while (getline(in_file, id))
		{
			query.push_back(id);
		}

		in_file.close();

		gpac(query, students, grades, out_file);
		
	}
}
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[]){
	vector<Student> students;
//Open file
	ifstream in_file;
	ofstream out_file;
	string id;
	int bad = 1;

	in_file.open(argv[1]);

	student(in_file, students, bad);	
	
	if (bad == 0){
	
		return 0;
	}
	out_file.open(argv[4]);
	
	for (size_t spot = 0; spot < students.size(); spot++)
	{
		out_file << students[spot].to_string();
	}
	out_file << endl;
	
	vector<Grade> grades;
		
	in_file.open(argv[2]);

	grade(in_file, grades, bad);	
	
	if (bad == 0){
	
		return 0;
	}

	for (size_t spot = 0; spot < grades.size(); spot++)
	{
		out_file << grades[spot].to_string();
	}
	out_file << endl;

	vector<string> query;
	
	in_file.open(argv[3]);

	queryf(in_file, query, bad, students, grades, out_file);	
	
	if (bad == 0){
	
		return 0;
	}
	out_file.close();
	
	return 0;
}
//---------------------------------------------------------------------------------------
