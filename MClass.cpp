#include "MClass.h"

char* WordsCountException = "Неверное количество слов! Строка должна содержать от 2 до 30 слов!";
char* LettersCountException = "Неверное количество букв! Слово должно содержать от 2 до 10 букв!";
char* StringEndException = "Строка должна заканчиваться точкой!";
char* EmptyStringException = "Введена пустая строка!";
char* StringFormatException = "Неверный формат строки!";

int MString::CheckingString(string s)
{
	int LettersCount = 0;

	int point = s.find('.');
	if (point == string::npos)
		throw StringEndException;

	if (s.length() == 2 && s[0] == '.' || s.length() == 0)
		throw EmptyStringException;

    istringstream ist(s);
    string tmp;
	//
    while (ist >> tmp)
	{
		if (tmp != ".")
		{
			if (tmp.find('.') != string::npos)
				tmp.erase(tmp.length() - 1);

			Words.push_back(tmp);
		}
	}
    
	WordsCount = Words.size();
	if (WordsCount < 2 || WordsCount > 30)
		throw WordsCountException;

	list <string>::iterator it;
	string word;
	for (int i = 0; i < WordsCount; i++)
	{
		it = Words.begin();
		advance(it, i);
		word = *it;
		LettersCount = word.length();
		if (LettersCount < 2 || LettersCount > 10)
			throw LettersCountException;
	}

	return WordsCount;
}

void MString::ChangeWord(string &w)
{
	char fWordCharacter = w[0];
	for (int i = 0; i < w.length() - 1; i++)
	{
		w[i] = w[i + 1];
	}
	w[w.length() - 1] = fWordCharacter;
}

void MString::Result(int &s)
{
	list <string>::iterator it;
	string fWord, word;

	it = Words.begin();
	advance(it, 0);
	fWord = *it;

	for (int i = 1; i < Words.size(); i++)
	{
		it = Words.begin();
		advance(it, i);
		word = *it;
		if (fWord != word)
		{ 
			ChangeWord(word);
			cout << word << endl;
			s++;
		}
	}
}


