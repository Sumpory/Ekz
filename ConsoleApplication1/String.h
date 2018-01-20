#pragma once

#include <iostream>
#include "stdafx.h"


class ourstring
{
public:
	int size = 256; // макс размер строки 
	char *str = new char[size]; // строка 
	int len = 0; // длина строки 
	ourstring() {} // пустой конструктор 
	~ourstring() { // деконструктор 
		delete[] str;
	}
	ourstring(const char*a); // конструктор ourstring a = "string"; 
	ourstring(std::string a);
	void add(const char* a); // добавляем в конец строки символы " " 
	void clear(); // очистка строки 
	void cut(int l, int r); //очистить с l по r ?? 
};
void ourstring::cut(int l, int r) //позиция, количество 
{
	if (l >= 0 && l + r < size) {
		for (int i = l; i + r < len; i++) {
			str[i] = str[i + r];
		}
		for (int i = l + r + 1; str[i]; i++) {
			str[i] = 0;
		}
		len -= r;
	}
	else
		std::cout << "Неверные введённые данные (выход за пределы строки)";
}
ourstring::ourstring(const char*a)
{
	while (a[len])
	{
		str[len] = a[len];
		len++;
	}
}
ourstring::ourstring(std::string a)
{
	len = a.length();
	for (int i = 0; i < len; i++) {
		str[i] = a[i];
	}
}
void ourstring::add(const char* a)
{
	int i = 0;
	while (a[i])
	{
		str[len + i] = a[i];
		i++;
	}
	len += i;
}
void ourstring::clear()
{
	for (int i = 0; i < len; i++) {
		str[i] = 0;
	}
	len = 0;

}