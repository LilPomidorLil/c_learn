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
/// Возведение в степень
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