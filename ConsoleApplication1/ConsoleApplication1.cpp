// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "Stroka.h "


int main()
{

	stroka wtf; 
	wtf.add("Hello world!");
	for (int i = 0; i < wtf.len; i++)
	{
		std::cout << wtf.str[i];
	}
	system("pause");
	
    return 0;
}


