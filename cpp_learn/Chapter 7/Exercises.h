#pragma once

# include <iostream>
# include <iomanip>
# include <string> // для strlen
# include <stdlib.h>
# include <math.h>

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

template <typename Type>
void swap(Type& first, Type& second)
{
	Type temp = first;
	first = second;
	second = temp;
}

/// <summary>
/// Задание 1
/// </summary>
/// <param name="string"> строка типа char</param>
void reversit(char string [])
{
	int len = strlen(string);
	for (int i = 0; i < len / 2; i++)
	{
		swap(string[i], string[len - i - 1]);
	}
}

/// <summary>
/// Задание 2
/// </summary>
class employee
{
private:
	std::string name;
	long num_employee;

public:
	employee() :
		name("andrew"), num_employee(0.0) {}

	friend std::istream& operator >> (std::istream& input, employee& obj)
	{
		std::cout << "Enter employee name and number -> " << std::endl;
		input >> obj.name >> obj.num_employee;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, employee& obj)
	{
		output << "Employee name is " << obj.name << ", number is " << obj.num_employee << std::endl;
		return output;
	}
};

int max_int(int array[], int i)
{
	int max = -10000;

	for (int k = 0; k < i; k++)
	{
		if (array[k] >= max)
		{
			max = array[k];
		}
	}
	return max;
}

/// <summary>
/// Задача 4.
/// </summary>
void task_4()
{
	const int MAX = 10;
	int array[MAX];
	char user_answer;
	int i = 0;
	int maxint;

	// input
	do
	{
		std::cout << "Enter digit->" << std::endl;
		std::cin >> array[i];
		std::cout << "Continue? [y/n]" << std::endl;
		std::cin >> user_answer;
		i++;
	} while (user_answer != 'n');

	// output
	for (int k = 0; k < i; k++)
	{
		std::cout << array[k] << " ";
	} std::cout << std::endl;

	maxint = max_int(array, i);
	std::cout << "Max is " << maxint << std::endl;
}


/// <summary>
/// Класс имитирующий повдение обыкновенных дробей для задания 5.
/// </summary>
class fraction
{
public:
	int up;
	int down;

	fraction() :
		up(1), down(1) {}

	fraction(int UP, int DOWN) :
		up(UP), down(DOWN) {}

	friend std::istream& operator >> (std::istream& input, fraction& obj)
	{
		std::cout << "Input up & down fraction in format 'UP/DOWN'" << std::endl;
		input >> obj.up; input.ignore(2, '/'); input >> obj.down;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, fraction& obj)
	{
		output << obj.up << "/" << obj.down << std::endl;
		return output;
	}

	fraction operator + (const fraction& another)
	{
		up = up * another.down + down * another.up;
		down = down * another.down;

		// сокращаем дробь
		lowterms(up, down);

		return fraction(up, down);
	}

	fraction operator += (const fraction& another)
	{
		up = up * another.down + down * another.up;
		down = down * another.down;

		// сокращаем дробь
		lowterms(up, down);

		return fraction(up, down);
	}

	fraction operator /= (const int& digit)
	{
		int down_;
		down = down * digit;
		lowterms(up, down);
		return fraction(up, down);
	}

	fraction operator / (const int& digit)
	{
		int down_;
		down = down * digit;
		lowterms(up, down);
		return fraction(up, down);
	}

	void lowterms(int& up, int& down)
	{
		int tup, tdown, temp, gcd;
		tup = abs(up);
		tdown = abs(down);

		if (tdown == 0) { throw std::invalid_argument("Den == 0. Check input"); }
		else if (tup == 0) { up = 0; down = 1; return; }

		// нахождение нода алгоритмом Евклида.

		while (tup != 0)
		{
			if (tup < tdown) { temp = tup; tup = tdown; tdown = temp; }

			tup -= tdown;
		}

		gcd = tdown;
		up /= gcd;
		down /= gcd;
	}
};

/// <summary>
/// Задание 5
/// </summary>
void task_5()
{
	const int MAXSIZE = 100;
	fraction array[MAXSIZE];
	int user_answer;
	int i = 0;

	do
	{
		fraction obj;
		std::cin >> obj;
		array[i] = obj;
		std::cout << "input 0 if stop" << std::endl;
		std::cin >> user_answer;
		i++;
	} while (user_answer != 0);

	int mean = 0;
	fraction sum(0, 1);
	for (int k = 0; k < i; k++)
	{
		sum += array[k];
	}
	sum /= i;
	std::cout << sum;
}


/// <summary>
/// Задача 8
/// </summary>
class safearay
{
private:
	static const int LIMIT = 3;
	int array[LIMIT];

public:
	int put(int index, int num)
	{
		if ((index > LIMIT - 1) || (index < 0)) { std::cout << "[class safearay] index of out list" << std::endl; return -1; }
		array[index] = num;
	}

	int get(int index)
	{
		if ((index > LIMIT - 1) || (index < 0)) { std::cout << "[class safearay] index of out list"; return -1; }
		return array[index];
	}

	int get_limit() const
	{
		return LIMIT;
	}
};

/// <summary>
/// Задание 9 - очередь
/// </summary>
class queue
{
private:
	safearay arr;					// безопасный массив
	int begin;						// индекс начала очереди
	int end;						// индекс конца очереди
	int LIMIT;						// предел по безопасному массиву

public:
	queue() :
		begin(0), end(0) 
	{
		LIMIT = arr.get_limit();
	}

	void put(int elem)
	{
		arr.put(end++, elem);
		if (end == LIMIT - 1) { end = 0; }
	}

	int get()
	{
		int firstin = arr.get(begin++);
		return firstin;
	}
};

