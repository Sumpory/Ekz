// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "Stroka.h "


int main()
{
	stroka wtf; 
	wtf.add("Hello World!\n"); // Заполнение строки
	for (int i = 0; i < wtf.len; i++)
	{
		std::cout << wtf.str[i];
	}

	wtf.cut(2, 2); // Удаление символов из строки
	for (int i = 0; i < wtf.len; i++)
	{
		std::cout << wtf.str[i];
	}

	wtf.clear();
		for (int i = 0; i < wtf.len; i++)
		{
			std::cout << wtf.str[i];
		}

		wtf.add("Odin!\n"); // Заполнение строки
		for (int i = 0; i < wtf.len; i++)
		{
			std::cout << wtf.str[i];
		}

	wtf.insert(4, ", Dva");
	for (int i = 0; i < wtf.len; i++)
	{
		std::cout << wtf.str[i];
	}

	system("pause");
	
    return 0;
}


