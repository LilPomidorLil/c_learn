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