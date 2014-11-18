#include "MClass.h"

char* FormatException = "�������� ������ ������!";

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
		    cout << "=================================== ���� �" << ++num << " ===================================" << endl;
		    cout << "                                  ������� �48" << endl;
		    cout << endl;
		    cout << "�������:" << endl << "   ���� ������������������, ���������� �� 2 �� 30 ����, � ������ �� �������" << endl 
		    	                       << "   �� 2 �� 10 ��������� ��������� ����; ����� ��������� ������� - �� �����" << endl
		    						   << "   ������ �������, ����� ���������� ����� - �����. ������ �� ������� ��� �����" << endl
		    						   << "   ������������������, ������� ������� �� ������� �����, ������������ ������" << endl
		    						   << "   �� ��� �� ���������� �������: ��������� ������ ����� � ����� �����." << endl;
		    cout << endl;
		    int method;
		    cout << "�������� ����� �������� ������: 1 - � �������� �����" << endl;
		    cout << "                                2 - � �������� ����������" << endl;
		    while (true)
		    {
		    	method = _getch();
		    	if (method != 49 && method != 50)
		    	{
		    		cout << "������ �������� �������! �������� ��� ���!" << endl;
					s++;
		    		continue;
		    	}
		    	else
		    	{
		    		cout << "�� ������� �������� ������ ";
		    		if (method == 49)
		    			cout << "� �������� �����." << endl;
		    		if (method == 50)
		    			cout << "� �������� ����������." << endl;
		    		cout << endl;
		    		break;
		    	}
		    }
		    
		    cout << "������� ������: " << endl;
		    if (method == 49)
		    {
		    	InputString(str);
				cout << endl << "��������� ������: " << str << endl;
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
				cout << endl << "��������� ������: " << str << endl;
		    	for (int i = 0; i < str.length(); i++)
		    	{
		    		if ((str[i] < 'A' || str[i] > 'Z') && str[i] != '.' && str[i] != ' ')
		    			throw FormatException;
		    	}
		    }

			MString obj(str);
			cout << "���������� ���� � ������: " << obj.CheckingString(str) << endl;
			cout << "����� � ������: " << endl;
			copy(obj.Words.begin(), obj.Words.end(), ostream_iterator <string> (cout, "\n"));
			s += obj.Words.size();
			cout << "���������: " << endl;
			obj.Result(s);
			s += 25;
		}
		catch(char* v)
		{
			s += 24;
			cout << endl << "������! " << v << endl;
		}
		cout << endl << "��� ����������� ������� ����� �������, " << endl << "��� ������ - ������� Esc..." << endl;
		cout << "===============================================================================" << endl;
		cout << endl;
	}
	while (_getch() != 27);

	return 0;
}

