#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	int grade[2];

public:
	Student(string _name, int arr[2]);
	string GetName();
	int* GetGrades();
};

