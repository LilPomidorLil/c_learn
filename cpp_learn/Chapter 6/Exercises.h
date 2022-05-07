#pragma once

# include <iostream>
# include <conio.h>  // для getche()

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