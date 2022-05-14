#pragma once

# include <iostream>
# include <iomanip>

/// <summary>
/// Вывод чисел (достаточно длинных) в консоль в красивом виде (округление, в нормальном виде и т.д.)
/// </summary>
void output_double()
{
	double a1 = 12345.12547931;
	double a2 = 0.000000000001;
	double a3 = 123;
	double a4 = 123456.12346578978;

	std::cout << std::setiosflags(std::ios::fixed)    // неэкспоненциальный вид
		<< std::setiosflags(std::ios::showpoint)      // всегда показывать точку
		<< std::setprecision(2)						  // 2 знака после запятой
		<< std::setw(8)								  // длина одной переменной при выводе максимум 8 символов
		<< a1 << std::endl << a2
		<< std::endl << a3 << std::endl << a4;

	/// Чтобы убрать флаги (std::ios::...) позднее, использовать resetiosflags
}

