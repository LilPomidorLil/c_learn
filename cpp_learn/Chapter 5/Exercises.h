#pragma once

# include <iostream>
// # include "msoftcon.h"


///////////////////////////////////////////////////////////////////////////////
///			Отрисовка кругов в консоле, нужно добавить msoftcon.h
///////////////////////////////////////////////////////////////////////////////



//struct circle
//{
//	int xCo, yCo;		// координаты центра
//	int radius;			// радиус
//	color fillcolor;	// цвет
//	fstyle fillstyle;	// стиль заполнения
//};
//
////-------------------------------------------
//void circ_draw(cirlce c)
//{
//	set_color(c.fillcolor);
//	set_fill_style(c.fillstyle);
//	draw_circle(c.xCo, c.yCo, c.radius);
//}
//
////-------------------------------------------

/// <summary>
/// Задание 2. 
/// Возведение в степень.
/// Если степень четная, то делим ее на два, иначе вычитаем единицу.
/// </summary>
/// <param name="n"> - число типа дабл</param>
/// <param name="p"> - в какую степень</param>
/// <returns></returns>
double power(double n, unsigned long long p)
{
	double result = 1;

	while (p)
	{
		if (p % 2 == 0)
		{
			p /= 2;
			n *= n;
		}
		else
		{
			p--;
			result *= n;
		}
	}

	return result;
}


/// <summary>
/// Задание 3.
/// Наименьшему числу присвоить нуль по ссылке. 
/// Если оба равны между собой, то оба нуля.
/// </summary>
/// <param name="first"> - ссылка на первое число типа инт</param>
/// <param name="second"> - ссылка на второе число типа инт</param>
void zeroSmaller(int& first, int& second)
{
	if (first < second)
	{
		first = 0;
	}
	else if (first > second)
	{
		second = 0;
	}
	else
	{
		first = 0;
		second = 0;
	}
}

/// <summary>
/// Для 4 задания структурочка.
/// </summary>
struct Distance
{
public:
	int feet;
	float inches;
	
	friend std::istream& operator >> (std::istream& input, Distance& obj)
	{
		std::cout << "Enter feet & inches" << std::endl;
		input >> obj.feet >> obj.inches;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Distance& obj)
	{
		output << "Feet = " << obj.feet << std::endl << "Inches = " << obj.inches << std::endl;
		return output;
	}
};

/// <summary>
/// Задание 4.
/// Нахождение наиболеьшей длины по структуре.
/// </summary>
/// <param name="first"> - структура типа Distance</param>
/// <param name="second"> - структура типа Distance</param>
/// <returns></returns>
Distance task_4(const Distance& first, const Distance& second)
{
	float sum_first = first.feet + 12 * first.inches;
	float sum_second = second.feet + 12 * second.inches;

	if (sum_first >= sum_second) return first;
	if (sum_first < sum_second) return second;
}
