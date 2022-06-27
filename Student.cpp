#include "Student.h"


using namespace std;

Student::Student(string _name, int arr[2])
{
	name = _name;
}

string Student::GetName()
{
	return name;
}

int* Student::GetGrades()
{
	return grade;
}