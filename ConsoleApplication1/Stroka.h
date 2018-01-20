#pragma once

#include <iostream>
#include "stdafx.h"


class stroka
{
public:
	int size = 1024; // ����������� ������ ������
	char *str = new char[size]; // ������ 
	int len = 0; // ����������� ������ ������ 
	stroka() {} 
	~stroka() 
	{ 
		delete[] str; // �������������, ����������� ������
	}
	stroka(const char*a); // ����������� stroka a = "stroka"; 
	stroka(std::string a);
	void add(const char* a); // ���������� ������
	void clear(); // ������� ������ ���������
	void cut(int l, int r); // �������� �������� � l �� r
	void insert(int a, char*b); // ������� ��������
};

void stroka::cut(int l, int r) // ������ �������, ���������� 
{
	if (l >= 0 && l + r < size) 
	{

		for (int i = l - 1; i + r < len; i++)
			{
				str[i] = str[i + r];
			}

		len -= r;

		for (int i = l; i < r; i++ )
			{
				str[i] = 0;
			}
		
	}
	else
		std::cout << "�������� �������� ������ (����� �� ������� ������)";
}

void stroka::insert(int a, char*b)
	{
		int l = 0;
		while (b[l])
			{
				l++;
			}
		if (len + l < size && a >= 0)
			{
				len += l;
				for (int i = a, j = 0; i < a + l; i++, j++) 
				{
					str[i + l] = str[i];
					str[i] = b[j];
				}
			}
		else
			std::cout << "����� �� ������� ������";
	}

stroka::stroka(const char*a)
	{
		while (a[len])
		{
			str[len] = a[len];
			len++;
		}
	}

stroka::stroka(std::string a)
	{
		len = a.length();
		for (int i = 0; i < len; i++) 
		{
			str[i] = a[i];
		}
	}

void stroka::add(const char* a)
	{
		int i = 0;
		while (a[i])
		{
			str[len + i] = a[i];
			i++;
		}
		len += i;
	}

void stroka::clear()
	{
		for (int i = 0; i <= size; i++) 
		{
			str[i] = 0;
		}
		len = 0;

	}