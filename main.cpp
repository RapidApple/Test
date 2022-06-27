#define _CRT_SECURE_NO_WARNINGS
#include <iostream>			// 출력을 나타냄
#include <sstream>			// string 형태의 문자열에 접근할 수 있게 통로를 만들어 줌
#include <fstream>			// 파일에 접근할 수 있는 통로를 만들어 줌
#include <string>			// 
#include "Student.h"

using namespace std;

int main(void)
{

	Student* Students[3];

	//파일로 부터 읽어서 객체 생성
	ifstream data("data.csv"); // input file stream - 들어오는 쪽으로만 길이 열림. 파일에 대한 경로를 찾아가서 열어.
	string line;		// string = 문자열 자체를 저장
	int cnt = 0;
	while (getline(data/*stream*/, line))			//line = 한줄 한줄 읽어
	{
		stringstream  lineStream(line);
		string        cell;
		int idx = 0;
		string tmpname = "";
		int tmpgrade[2];
		while (getline(lineStream, cell, ','))		// ,로 저장된 데이터 하나를 cell에 저장
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