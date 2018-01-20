#pragma once

#include <iostream>
#include "stdafx.h"


class string
{
public:
	int size = 256; // ���� ������ ������ 
	char *str = new char[size]; // ������ 
	int len = 0; // ����� ������ 
	string() {} // ������ ����������� 
	~string() { // ������������� 
		delete[] str;
	}
	string(const char*a); // ����������� ourstring a = "string"; 
	string(std::string a);
	void add(const char* a); // ��������� � ����� ������ ������� " " 
	void clear(); // ������� ������ 
	void cut(int l, int r); //�������� � l �� r ?? 
};

void string::cut(int l, int r) //�������, ���������� 
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
		std::cout << "�������� �������� ������ (����� �� ������� ������)";
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