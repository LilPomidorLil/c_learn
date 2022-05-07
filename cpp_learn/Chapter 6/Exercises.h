#pragma once

# include <iostream>

/// <summary>
/// Задача 1. 
/// Класс, имитирующий поведение стандартного типа инт с перегрузкой операторов.
/// </summary>
class Int
{
private:
	int a;

public:
	Int() : a(0) {}
	
	Int(int A) : a(A) {}

	friend std::istream& operator >> (std::istream& input, Int& obj)
	{
		input >> obj.a;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Int& obj)
	{
		output << obj.a;
		return output;
	}

	friend Int operator + (Int& first, Int& second)
	{
		Int third(first.a + second.a);
		return third;
	}

	friend Int operator - (Int& first, Int& second)
	{
		Int third(first.a - second.a);
		return third;
	}
};