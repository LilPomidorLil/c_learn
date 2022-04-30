#pragma once

# include <iostream>
# include <map>
# include <string>


/// <summary>
/// Структура для задания 1
/// </summary>
struct phone
{
private:
	int city;
	int phone_station;
	int phone_abonent;

public:
	phone() : 
		city(7), phone_station(999), phone_abonent(5716679) {}
	
	phone(int city_, int phone_station_, int phone_abonent_) :
		city(city_), phone_station(phone_station_), phone_abonent(phone_abonent_) {}

	friend std::istream& operator >> (std::istream& input, phone& struct_)
	{
		std::cout << "Enter the country code, city and other part:" << std::endl;
		input >> struct_.city >> struct_.phone_station >> struct_.phone_abonent;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, phone& struct_)
	{
		output << "My phone is -> +7-999-5716679" << std::endl;
		output << "Your phone is -> +" << struct_.city << "-" << struct_.phone_station << "-" << struct_.phone_abonent << std::endl;
		return output;
	}
};



/// <summary>
/// Задание 2
/// </summary>
struct point
{
private:
	float x;
	float y;

public:
	point() :
		x(0), y(0) {}

	point(float X, float Y) :
		x(X), y(Y) {}

	friend std::istream& operator >> (std::istream& input, point& obj)
	{
		std::cout << "Enter 'x' & 'y' coordinate:" << std::endl;
		input >> obj.x >> obj.y;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, point& obj)
	{
		output << "This point coordinate ->" << std::endl << "X = " << obj.x << std::endl << "Y = " << obj.y << std::endl;
		return output;
	}

	friend point operator + (point& p1, point& p2)
	{
		point p3;
		p3.x = p1.x + p2.x;
		p3.y = p1.y + p2.y;
		return p3;
	}
};



/// <summary>
/// Внутреннию интерфейсы для решения подзадач
/// </summary>
namespace internal {
	struct Distance
	{
		// 1 фут = 12 дюймам
		int feet;			// кол-во футов
		float inches;		// кол-во дюймов
	};
}



/// <summary>
/// Задание 3
/// </summary>
struct Volume
{
private:
	internal::Distance length;
	internal::Distance width;
	internal::Distance height;

	static float volume_calc(Volume& obj)
	{
		float volume;

		volume = (obj.length.feet * obj.length.inches) *
			(obj.width.feet * obj.width.inches) *
			(obj.height.feet * obj.height.inches);

		return volume;
	}

public:
	friend std::istream& operator >> (std::istream& input, Volume& obj)
	{
		std::cout << "Enter the 'length' of the room in the format of feet and inches separated by a space ->" << std::endl;
		input >> obj.length.feet >> obj.length.inches;
		std::cout << std::endl;

		std::cout << "Enter the 'width' of the room in the format of feet and inches separated by a space ->" << std::endl;
		input >> obj.width.feet >> obj.width.inches;
		std::cout << std::endl;

		std::cout << "Enter the 'height' of the room in the format of feet and inches separated by a space ->" << std::endl;
		input >> obj.height.feet >> obj.height.inches;
		std::cout << std::endl;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Volume& obj)
	{
		float volume;
		volume = volume_calc(obj);

		output << "Calculated volume -> " << volume << " square units" << std::endl;
		return output;
	}
}; 


/// <summary>
/// Задание 4
/// </summary>
struct employee
{
private:
	int number;		// номер сотрудника
	float salary;   // зарплата

public:
	friend std::istream& operator >> (std::istream& input, employee& obj)
	{
		std::cout << "Enter the employee number: ";
		input >> obj.number;

		std::cout << "Specify the salary: ";
		input >> obj.salary;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, employee& obj)
	{
		output << "Employee with a number '" << obj.number << "' has a salary in the amount of '" << obj.salary << "' rubles" << std::endl;
		return output;
	}
};


/// <summary>
/// Задание 5
/// </summary>
struct date
{
private:
	int day; 
	int month;
	int year;

public:
	friend std::istream& operator >> (std::istream& input, date& obj)
	{
		/// Обратить особое внмание на 'std::cin.ignore' - первый параметр - длина строки, на которой он будет отлавливать и игнорить указанный во
		/// 2 параметре значении. Сейчас он работает так -> 
		/// после крайне введенного значения он ищет среди 2 символов вперед '\n' а затем перестает его искать.
		
		std::cout << "Enter a date on format '31/12/2002'" << std::endl;
		input >> obj.day; input.ignore(2, '/'); input >> obj.month; input.ignore(2, '/'); input >> obj.year;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, date& obj)
	{
		output << "Date is " << obj.day << "/" << obj.month << "/" << obj.year << std::endl;
		return output;
	}
};


/// <summary>
/// Задача 6
/// </summary>
void task_6()
{
	enum etype
	{
		laborer,
		secretary,
		manager,
		accountant,
		executive,
		researcher
	};

	std::map<etype, std::string> map =
	{
		std::make_pair(laborer, "laborer"),
		std::make_pair(secretary, "secretary"),
		std::make_pair(manager, "manager"),
		std::make_pair(accountant, "accountant"),
		std::make_pair(executive, "executive"),
		std::make_pair(researcher, "researcher"),
	};

	std::map<char, etype> tips =
	{
		std::make_pair('l', laborer),
		std::make_pair('s', secretary),
		std::make_pair('m', manager),
		std::make_pair('a', accountant),
		std::make_pair('e', executive),
		std::make_pair('r', researcher)
	};

	char user_request;
	std::cout << "Enter first letter: ";
	std::cin >> user_request;

	etype type = tips[user_request];

	std::cout << "Full title of the position: " << map[type] << std::endl;
}


/// <summary>
/// Задание 7
/// </summary>
struct Employee
{
private:
	employee employee_info;
	date data;

public:
	friend std::istream& operator >> (std::istream& input, Employee& obj)
	{
		input >> obj.employee_info >> obj.data;
		std::cout << std::endl;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, Employee& obj)
	{
		output << obj.employee_info << obj.data << std::endl;
		return output;
	}
};


/// <summary>
/// Задание 8
/// </summary>
struct fraction
{
private:
	int up;
	int down;

public:
	friend std::istream& operator >> (std::istream& input, fraction& obj)
	{
		std::cout << "Enter the numerator and denominator of the fraction separated by a space ->" << std::endl;
		input >> obj.up >> obj.down;
		return input;
	}

	friend std::ostream& operator << (std::ostream& output, fraction& obj)
	{
		output << "Fraction = " << obj.up << "/" << obj.down << std::endl;
		return output;
	}

	friend fraction operator + (fraction& first, fraction& second)
	{
		fraction third;

		third.up = (first.up * second.down + first.down * second.up);
		third.down = (first.down * second.down);
		return third;
	}
};


/// <summary>
/// Задание 9
/// </summary>
struct Time
{
private:
	int hours;
	int minutes;
	int seconds;
	long totalsec;

public:
	// На самом деле конструктор здесь не нужен, но пусть будет.
	Time() :
		hours(0), 
		minutes(0), 
		seconds(0), 
		totalsec(0) 
	{}

	void input()
	{
		std::cout << "Enter the time in the format 12:31:56" << std::endl;
		std::cin >> hours; std::cin.ignore(2, ':'); std::cin >> minutes; std::cin.ignore(2, ':'); std::cin >> seconds;
	}

	void output()
	{
		totalsec = hours * 3600 + minutes * 60 + seconds;
		std::cout << "Since the beginning of the day has passed " << totalsec << " sec." << std::endl;
	}
};

