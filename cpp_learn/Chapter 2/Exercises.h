﻿#pragma once


# include <iostream>
# include <iomanip>   // используется для выравнивания строк в консоли с той стороны, которой нужно
# include <ctype.h>   // для функции islower(), которая проверяет букву на строчность: 0 - заглавная, иначе все остальные цифры

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
		<< std::setiosflags(std::ios::left) << std::setw(15) << "Franc" << std::setw(15) << user_request / frank << std::endl
		<< std::setiosflags(std::ios::left) << std::setw(15) << "German brand" << std::setw(15) << user_request / german << std::endl
		<< std::setiosflags(std::ios::left) << std::setw(15) << "Japanese Yen" << std::setw(15) << user_request / japan << std::endl;
}