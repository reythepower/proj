#include "MClass.h"

char* FormatException = "Неверный формат строки!";

HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
void CoordPosition(int x, int y)
{
	COORD Coordinates = {x, y};
	SetConsoleCursorPosition(hOUTPUT, Coordinates);
}

int s = 15;
void InputString(string &str)
{
	int character;// hello
	int k = -1;
	do
	{
		character = _getch();
		if ((character >= 65 && character <= 90) || character == 32 || character == 46 || character == 8 || character == 13)
		{
			if (character == 8)
			{
				if (str.length() != 0)
				{
					str.erase(str.length() - 1, 1);
					CoordPosition(k, s);
					cout << " ";
					k--;
				}
			}
			else
			{
				str += (char)character;
				k++;
			}
			
			cout << (char)character;
		}
	}
	while (character != 13);
}

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	
	string str;
	int num = 0;
	do
	{
		try
		{
		    str = "";
		    cout << "=================================== Тест №" << ++num << " ===================================" << endl;
		    cout << "                                  Вариант №48" << endl;
		    cout << endl;
		    cout << "Задание:" << endl << "   Дана последовательность, содержащая от 2 до 30 слов, в каждом из которых" << endl 
		    	                       << "   от 2 до 10 прописных латинских букв; между соседними словами - не менее" << endl
		    						   << "   одного пробела, после последнего слова - точка. Выдать на дисплей все слова" << endl
		    						   << "   последовательности, которые отличны от первого слова, преобразовав каждое" << endl
		    						   << "   из них по следующему правилу: перенести первую букву в конец слова." << endl;
		    cout << endl;
		    int method;
		    cout << "Выберите метод проверки строки: 1 - в процессе ввода" << endl;
		    cout << "                                2 - в процессе вычисления" << endl;
		    while (true)
		    {
		    	method = _getch();
		    	if (method != 49 && method != 50)
		    	{
		    		cout << "Нажата неверная клавиша! Выберите еще раз!" << endl;
					s++;
		    		continue;
		    	}
		    	else
		    	{
		    		cout << "Вы выбрали проверку строки ";
		    		if (method == 49)
		    			cout << "в процессе ввода." << endl;
		    		if (method == 50)
		    			cout << "в процессе вычисления." << endl;
		    		cout << endl;
		    		break;
		    	}
		    }
		    
		    cout << "Введите строку: " << endl;
		    if (method == 49)
		    {
		    	InputString(str);
				cout << endl << "Введенная строка: " << str << endl;
				int point = str.find('.');
				if (point != str.length() - 2)
				{
					throw FormatException;
				}
		    }
		    else if (method == 50)
		    {
				s++;
		    	getline(cin, str);
				cout << endl << "Введенная строка: " << str << endl;
		    	for (int i = 0; i < str.length(); i++)
		    	{
		    		if ((str[i] < 'A' || str[i] > 'Z') && str[i] != '.' && str[i] != ' ')
		    			throw FormatException;
		    	}
		    }

			MString obj(str);
			cout << "Количество слов в строке: " << obj.CheckingString(str) << endl;
			cout << "Слова в строке: " << endl;
			copy(obj.Words.begin(), obj.Words.end(), ostream_iterator <string> (cout, "\n"));
			s += obj.Words.size();
			cout << "Результат: " << endl;
			obj.Result(s);
			s += 25;
		}
		catch(char* v)
		{
			s += 24;
			cout << endl << "Ошибка! " << v << endl;
		}
		cout << endl << "Для продолжения нажмите любую клавишу, " << endl << "для выхода - клавишу Esc..." << endl;
		cout << "===============================================================================" << endl;
		cout << endl;
	}
	while (_getch() != 27);

	return 0;
}

