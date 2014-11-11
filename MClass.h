#ifndef _MCLASS_H
#define _MCLASS_H

#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
#include <list>
#include <conio.h>
#include <windows.h>

using namespace std;

class MString
{
private:
	string Str;
	int WordsCount;
public:
	list <string> Words;

	MString(string s)
	{
		Str = s;
		WordsCount = 0;
	}
	
	int CheckingString(string);
	void ChangeWord(string &);
	void Result(int &);
};
#endif _MCLASS_H;