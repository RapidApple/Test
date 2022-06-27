#define _CRT_SECURE_NO_WARNINGS
#include <iostream>			// ����� ��Ÿ��
#include <sstream>			// string ������ ���ڿ��� ������ �� �ְ� ��θ� ����� ��
#include <fstream>			// ���Ͽ� ������ �� �ִ� ��θ� ����� ��
#include <string>			// 
#include "Student.h"

using namespace std;

int main(void)
{

	Student* Students[3];

	//���Ϸ� ���� �о ��ü ����
	ifstream data("data.csv"); // input file stream - ������ �����θ� ���� ����. ���Ͽ� ���� ��θ� ã�ư��� ����.
	string line;		// string = ���ڿ� ��ü�� ����
	int cnt = 0;
	while (getline(data/*stream*/, line))			//line = ���� ���� �о�
	{
		stringstream  lineStream(line);
		string        cell;
		int idx = 0;
		string tmpname = "";
		int tmpgrade[2];
		while (getline(lineStream, cell, ','))		// ,�� ����� ������ �ϳ��� cell�� ����
		{
			if (idx == 0)
			{
				tmpname = cell;
			}
			else
			{
				tmpgrade[idx - 1] = stoi(cell);
			}
			idx++;
		}

		Students[cnt] = new Student(tmpname, tmpgrade);
		cnt++;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << Students[i]->GetName() << endl;
	}


	return 0;
}