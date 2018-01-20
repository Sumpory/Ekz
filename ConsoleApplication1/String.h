#pragma once

#include <iostream>
#include "stdafx.h"


class ourstring
{
public:
	int size = 256; // ���� ������ ������ 
	char *str = new char[size]; // ������ 
	int len = 0; // ����� ������ 
	ourstring() {} // ������ ����������� 
	~ourstring() { // ������������� 
		delete[] str;
	}
	ourstring(const char*a); // ����������� ourstring a = "string"; 
	ourstring(std::string a);
	void add(const char* a); // ��������� � ����� ������ ������� " " 
	void clear(); // ������� ������ 
	void cut(int l, int r); //�������� � l �� r ?? 
};
void ourstring::cut(int l, int r) //�������, ���������� 
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
		std::cout << "�������� �������� ������ (����� �� ������� ������)";
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