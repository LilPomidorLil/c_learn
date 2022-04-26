#pragma once


# include <iostream>
# include <iomanip>   // используется для выравнивания строк в консоли с той стороны, которой нужно
# include <ctype.h>   // для функции islower(), которая проверяет букву на строчность: 0 - заглавная, иначе все остальные цифры
# include <cmath>     // для round

void task_1()
{
	float one_foot = 7.481;
	float user_request;
	std::cout << "Enter the number of gallons: " << std::endl;
	std::cin >> user_request;
	float ans = user_request / one_foot;
	std::cout << "Equivalent volume in cubic feet: " << ans << std::endl;
}

void task_2()
{
	std::cout << std::setw(4) << "1990" << std::setw(10) << "135" << std::endl
		<< std::setw(4) << "1991" << std::setw(10) << "7290" << std::endl
		<< std::setw(4) << "1992" << std::setw(10) << "11300" << std::endl
		<< std::setw(4) << "1993" << std::setw(10) << "16200" << std::endl;
}

void task_3()
{
	int digit = 10;
	std::cout << digit << std::endl;
	digit *= 2;
	std::cout << digit << std::endl;
	std::cout << --digit << std::endl;
}

void task_4()
{
	std::cout << "I'm too lazy to writ this poem \n but I will always remember \n\t how long I've been teaching Siska!" << std::endl;
}

void task_5()
{
	char user_request;
	std::cout << "Enter symbol:" << std::endl;
	std::cin >> user_request;
	std::cout << islower(user_request) << std::endl;
}

void task_6()
{
	const float sterling = 1.487;
	const float frank = 0.172;
	const float german = 0.584;
	const float japan = 0.00955;

	float user_request;
	std::cout << "Enter the number of dollars: " << std::endl;
	std::cin >> user_request;

	std::cout << std::setiosflags(std::ios::left) << std::setw(15) << "Pound Sterling" << std::setw(15) << user_request / sterling << std::endl
		 << std::setw(15) << "Franc" << std::setw(15) << user_request / frank << std::endl
		 << std::setw(15) << "German brand" << std::setw(15) << user_request / german << std::endl
		 << std::setw(15) << "Japanese Yen" << std::setw(15) << user_request / japan << std::endl;
}

void task_7 ()
{
	float user_request;
	std::cout << "Enter the temperature in Celsius: " << std::endl;
	std::cin >> user_request;
	user_request *= 1.8;
	user_request += 32;
	std::cout << "The temperature in Fahrenheit is: " << user_request << std::endl;
}

void task_8()
{
	const int pop1 = 8425785, pop2 = 47, pop3 = 9761;

	std::cout << std::setiosflags(std::ios::left) << std::setfill('.') << std::setw(9) << "City" << std::setiosflags(std::ios::right)  << std::setw(20) << "Population" << std::endl
		<< std::setw(9) << "Moscow" << std::setw(20) << pop1 << std::endl
		<< std::setw(9) << "Kirov" << std::setw(20) << pop2 << std::endl
		<< std::setw(9) << "Ugrumovka" << std::setw(20) << pop3 << std::endl;
}

void task_9()
{
	int a, b, c, d;
	char dummy;

	std::cout << "Enter the value of 2 fractions via Enter: " << std::endl;
	std::cin >> a >> dummy >> b;
	std::cin >> c >> dummy >> d;
	
	a = a * d + b * c;
	c = b * d;

	std::cout << "The sum of fractions is equal to: " << a << "/" << c << std::endl;
}

void task_10()
{
	int pound, shilling, pens;
	std::cout << "Enter the number of pounds: ";
	std::cin >> pound;
	std::cout << "Enter the number of shillings: ";
	std::cin >> shilling;
	std::cout << "Enter the number of pence: ";
	std::cin >> pens;

	float ans = round(((20 * pound + shilling) * 12 + pens) / 2.4) / 10;
	std::cout << "Decimal pounds: " << "£" << ans / 10 << std::endl;
}

void task_11()
{
	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "Surname" << std::setw(10) << "Name" << std::setw(20) << "Address" << std::setw(15) << "City" << std::endl
		<< std::setw(55) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "Petrov" << std::setw(10) << "Vasiliy" << std::setw(20) << "Klenovaya 16" << std::setw(15) << "Sankt-Petersburg" << std::endl
		<< std::setw(10) << "Ivanov" << std::setw(10) << "Sergey" << std::setw(20) << "Osinovaya 3" << std::setw(15) << "Naxodka" << std::endl
		<< std::setw(10) << "Sidorov" << std::setw(10) << "Ivan" << std::setw(20) << "Berezovaya 21" << std::setw(15) << "Kaliningrad" << std::endl;
}