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

/// <summary>
/// Задание 2.
/// </summary>
class toolBooth
{
private:
	unsigned int total_car;
	double total_sum;

public:
	toolBooth() : total_car(0), total_sum(0) {}

	void payingCar()
	{
		total_car++;
		total_sum += 0.5;
	}

	void nopayCar()
	{
		total_car++;
	}

	void display() const
	{
		int not_pay_car_total = 2 * (total_car * 0.5 - total_sum);
		std::cout << "Total car = " << total_car << std::endl << "Total sum = " << total_sum << std::endl << "Not payed " << not_pay_car_total;
	}

	void run()
	{
		char ch;
		do
		{
			std::cout << "'Y' if ~payingCar~, else 'N'" << std::endl;

			std::cin >> ch;

			switch (ch)
			{
			case 'Y':
				this->payingCar();
				break;

			case 'N':
				this->nopayCar();
				break;

			case 'S':
				break;

			default:
				std::cout << "I can't understand!" << std::endl;
				break;
			}
		} while (ch != 'S');

		this->display();
	}
};

/// <summary>
/// Задача 3.
/// </summary>
class Time
{
private:
	int hour;
	int minute;
	int sec;

public:
	Time() : 
		hour(0), minute(0), sec(0) {}

	Time(int HOUR, int MINUTE, int SEC) :
		hour(HOUR), minute(MINUTE), sec(SEC) {}

	void show_data() const
	{
		std::cout << hour << ":" << minute << ":" << sec << std::endl;
	}

	void add_data(const Time& first, const Time& second)
	{
		int minute_append = 0, sec_append = 0;

		sec = first.sec + second.sec;

		if (sec >= 60)
		{
			sec %= 60;
			sec_append = 1;
		}

		minute = first.minute + second.minute + sec_append;

		if (minute >= 60)
		{
			minute %= 60;
			minute_append = 1;
		}

		hour = first.hour + second.hour + minute_append;

		if (hour >= 24)
		{
			hour %= 24;
		}
	}
};

/// <summary>
/// Задание 4.
/// </summary>
class Employee
{
private:
	int employee_number;
	int salary;

public:
	Employee() :
		employee_number(0), salary(0) {}

	friend std::istream& operator >> (std::istream& input, Employee& obj)
	{
		std::cout << "Enter employee number and salary" << std::endl;
		input >> obj.employee_number >> obj.salary;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Employee& obj)
	{
		output << "Employee number and salary ";
		output << obj.employee_number << " " << obj.salary << std::endl;
		return output;
	}
};

