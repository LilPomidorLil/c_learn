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
class employee
{
private:
	int employee_number;
	int salary;

public:
	employee() :
		employee_number(0), salary(0) {}

	friend std::istream& operator >> (std::istream& input, employee& obj)
	{
		std::cout << "Enter employee number and salary" << std::endl;
		input >> obj.employee_number >> obj.salary;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, employee& obj)
	{
		output << "Employee number and salary ";
		output << obj.employee_number << " " << obj.salary << std::endl;
		return output;
	}
};

/// <summary>
/// Задание 5.
/// </summary>
class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date() :
		day(0), month(0), year(0) {}

	friend std::istream& operator >> (std::istream& input, Date& obj)
	{
		std::cout << "Enter date on format ~ DD/MM/YYYY" << std::endl;
		input >> obj.day; input.ignore(2, '/'); input >> obj.month; input.ignore(2, '/'); input >> obj.year;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Date& obj)
	{
		output << "Date is " << obj.day << "/" << obj.month << "/" << obj.year << std::endl;
		return output;
	}
};


/// <summary>
/// Задача 6.
/// Класс employee на стероидах
/// </summary>
class Employee
{
private:
	employee empl;
	Date data;

	enum etype
	{
		laborer = 0,
		secretary,
		manager,
		accountant,
		executive,
		researcher
	};

	int work_type;

public:
	friend std::istream& operator >> (std::istream& input, Employee& obj)
	{
		char ch;

		input >> obj.empl >> obj.data;
		std::cout << "Input first char work: ";
		input >> ch;
		switch (ch)
		{
		case 'l':
			obj.work_type = obj.laborer;
			break;

		case 's':
			obj.work_type = obj.secretary;
			break;

		case 'm':
			obj.work_type = obj.manager;
			break;

		case 'a':
			obj.work_type = obj.accountant;
			break;

		case 'e':
			obj.work_type = obj.executive;
			break;

		case 'r':
			obj.work_type = obj.researcher;
			break;
		}

		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Employee& obj)
	{
		output << obj.empl << obj.data;
		switch (obj.work_type)
		{
		case 0:
			output << "Work is laborer" << std::endl << std::endl;
			break;

		case 1:
			output << "Work is secretary" << std::endl << std::endl;	
			break;

		case 2:
			output << "Work is manager" << std::endl << std::endl;	
			break;

		case 3:
			output << "Work is accountant" << std::endl << std::endl;		
			break;

		case 4:
			output << "Work is executive" << std::endl << std::endl;		
			break;

		case 5:
			output << "Work is researcher" << std::endl << std::endl;			
			break;
		}

		return output;
	}
};