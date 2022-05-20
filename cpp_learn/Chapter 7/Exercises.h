﻿#pragma once

# include <iostream>
# include <iomanip>
# include <string> // для strlen

/// <summary>
/// Вывод чисел (достаточно длинных) в консоль в красивом виде (округление, в нормальном виде и т.д.)
/// </summary>
void output_double()
{
	double a1 = 12345.12547931;
	double a2 = 0.000000000001;
	double a3 = 123;
	double a4 = 123456.12346578978;

	std::cout << std::setiosflags(std::ios::fixed)    // неэкспоненциальный вид
		<< std::setiosflags(std::ios::showpoint)      // всегда показывать точку
		<< std::setprecision(2)						  // 2 знака после запятой
		<< std::setw(8)								  // длина одной переменной при выводе максимум 8 символов
		<< a1 << std::endl << a2
		<< std::endl << a3 << std::endl << a4;

	/// Чтобы убрать флаги (std::ios::...) позднее, использовать resetiosflags
}

template <typename Type>
void swap(Type& first, Type& second)
{
	Type temp = first;
	first = second;
	second = temp;
}

/// <summary>
/// Задание 1
/// </summary>
/// <param name="string"> строка типа char</param>
void reversit(char string [])
{
	int len = strlen(string);
	for (int i = 0; i < len / 2; i++)
	{
		swap(string[i], string[len - i - 1]);
	}
}

/// <summary>
/// Задание 2
/// </summary>
class employee
{
private:
	std::string name;
	long num_employee;

public:
	employee() :
		name("andrew"), num_employee(0.0) {}

	friend std::istream& operator >> (std::istream& input, employee& obj)
	{
		std::cout << "Enter employee name and number -> " << std::endl;
		input >> obj.name >> obj.num_employee;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, employee& obj)
	{
		output << "Employee name is " << obj.name << ", number is " << obj.num_employee << std::endl;
		return output;
	}
};

