#pragma once

#include <iostream>
#include "stdafx.h"


class string
{
public:
	int size = 256; // макс размер строки 
	char *str = new char[size]; // строка 
	int len = 0; // длина строки 
	string() {} // пустой конструктор 
	~string() { // деконструктор 
		delete[] str;
	}
	string(const char*a); // конструктор ourstring a = "string"; 
	string(std::string a);
	void add(const char* a); // добавляем в конец строки символы " " 
	void clear(); // очистка строки 
	void cut(int l, int r); //очистить с l по r ?? 
};

void string::cut(int l, int r) //позиция, количество 
{
	if (l >= 0 && l + r < size) {
		for (int i = l; i + r < len; i++) {
			str[i] = str[i + r];
		}
		for (int i = l + r + 2; str[i] && i < size; i++) {
			str[i] = 0;
		}
		len -= r;
	}
	else
		std::cout << "Неверные введённые данные (выход за пределы строки)";
}

string::string(const char*a)
{
	while (a[len])
	{
		str[len] = a[len];
		len++;
	}
}
string::string(std::string a)
{
	len = a.length();
	for (int i = 0; i < len; i++) {
		str[i] = a[i];
	}
}

void string::add(const char* a)
{
	int i = 0;
	while (a[i])
	{
		str[len + i] = a[i];
		i++;
	}
	len += i;
}

void string::clear()
{
	for (int i = 0; i < len; i++) {
		str[i] = 0;
	}
	len = 0;

}