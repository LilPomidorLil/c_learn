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
/// Нахождение наибольшей длины по структуре.
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

/// <summary>
/// Задание 5.
/// Перевод в секунд текущего времени относительно начала суток.
/// </summary>
/// <param name="hour"> - текущий час</param>
/// <param name="minute"> - текущая минута</param>
/// <param name="sec"> - текущая секунда</param>
/// <returns></returns>
long hms_to_sec(const int hour, const int minute, const int sec)
{
	return static_cast<long>(3600 * hour + 60 * minute + sec);
}

/// <summary>
/// Задание 6.
/// </summary>
struct Time
{
private:
	int hours;
	int minute;
	int sec;

public:
	Time() :
		hours(0), minute(0), sec(0) {}

	Time(const int HOURS, const int MINUTE, const int SEC) : 
		hours(HOURS), minute(MINUTE), sec(SEC) {}


	friend std::istream& operator >> (std::istream& input, Time& obj)
	{
		std::cout << "Input 'hours', 'minutes', 'sec' ->" << std::endl;
		input >> obj.hours >> obj.minute >> obj.sec;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, const Time& obj)
	{
		output << obj.hours << " Hours " << obj.minute << " Minute" << obj.sec << " Sec." << std::endl;
		return output;
	}

	const unsigned long time_to_secs(const Time& obj)
	{
		return static_cast<unsigned long>(3600 * obj.hours + 60 * obj.minute + obj.sec);
	}

	Time secs_to_time(const unsigned long secs)
	{
		Time obj;
		obj.hours = secs / 3600;
		obj.minute = (secs - obj.hours * 3600) / 60;
		obj.sec = secs - obj.hours * 3600 - obj.minute * 60;
		return obj;
	}
};

/// <summary>
/// Задача 8
/// </summary>
/// <typeparam name="Type"></typeparam>
/// <param name="first"></param>
/// <param name="second"></param>
template <typename Type>
void swap(Type& first, Type& second)
{
	Type temporary = first;
	first = second;
	second = temporary;
}

/// <summary>
/// Задача 9. 
/// Своп структур.
/// </summary>
/// <param name="first"></param>
/// <param name="second"></param>
void swap(Time& first, Time& second)
{
	Time temporary = first;
	first = second;
	second = temporary;
}