#pragma once

# include <iostream>
# include <iomanip>
# include <conio.h>  // для getche()

void test_func_debug()
{
	for (int numb = 1; numb < 10; numb++)
	{
		std::cout << std::setw(4) << numb;
		int cube = numb * numb * numb;
		std::cout << std::setw(6) << cube << std::endl;
	}
}

void showprim()
{
	const unsigned char WHITE = 219; // белый цвет для простых чисел
	const unsigned char GRAY = 176;  // серый цвет для остальных символов
	unsigned char ch;

	// начинаем пробегаться по каждой позиции в консоле
	for (int count = 0; count < 800 * 25 - 1; count++)
	{
		ch = WHITE; 

		for (int j = 2; j < count; j++)
		{
			if (count % j == 0)
			{
				ch = GRAY;
				break;
			}
		}

		std::cout << ch;
	}
}

void task_1()
{
	int user_request, mnozhitel = 1;
	std::cout << "Enter a number: ";
	std::cin >> user_request;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << user_request * mnozhitel;
			mnozhitel++;
		}
		std::cout << std::endl;
	}
}

void celcius(float& user_request)
{
	user_request *= 1.8;
	user_request += 32;
}

void fahrenheit(float& user_request)
{
	user_request -= 32;
	user_request /= 1.8;
}

void task_2()
{
	float user_request;
	char user_answer;
	std::cout << "Enter C - Celsius.\nEnter F - Fahrenheit." << std::endl;
	std::cin >> user_answer;

	switch (user_answer)
	{
	case 'C':
		std::cout << "Enter temperature: ";
		std::cin >> user_request;
		celcius(user_request);
		std::cout << "Temperature in Fahrenheit = " << user_request << std::endl;
		break;

	case 'F':
		std::cout << "Enter temperature: ";
		std::cin >> user_request;
		fahrenheit(user_request);
		std::cout << "Temperature in Celcius = " << user_request << std::endl;
		break;

	default:
		std::cout << "Non-defined answer. Check input data and restart programm." << std::endl;
	}
}

void task_3()
{
	std::cout << "Enter a number: ";
	char ch;
	unsigned long answer = 0;

	while ((ch = _getche()) != '\r') answer = answer * 10 + ch - '0';
	std::cout << "It turned out to be a number: " << answer << std::endl;
}

void switch_result(float& first, float& second, char& dummy)
{
	switch (dummy)
	{
	case '+':
		std::cout << first + second;
		break;

	case '-':
		std::cout << first - second;
		break;

	case '*':
		std::cout << first * second;
		break;

	case '/':
		std::cout << first / second;
		break;
	default:
		std::cout << "Non-defined operand";
		break;
	}
}

void task_4()
{
	float first, second;
	char dummy;
	char user_answer;

	do
	{
		std::cout << "Enter request: ";
		std::cin >> first >> dummy >> second;
		switch_result(first, second, dummy);
		std::cout << "\nContinue? [y/n]: ";
		std::cin >> user_answer;
	} while (user_answer != 'n');
}

void task_5()
{
	for (int i = 0; i < 20; i++)
	{
		std::cout << std::setw(i) << "" << std::setfill('X') << std::endl;
	}
}

void task_6()
{
	int user_request;
	unsigned long ans = 1;

	std::cout << "Enter a number: ";
	std::cin >> user_request;

	do
	{
		for (int i = user_request; i > 0; i--)
		{
			ans *= i;
		}

		std::cout << "Factorial = " << ans << std::endl;

		ans = 1;

		std::cout << "Enter a number: ";
		std::cin >> user_request;
	} while (user_request != 0);
}