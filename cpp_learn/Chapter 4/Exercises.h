#pragma once

# include <iostream>


/// <summary>
/// Структура для задания 1
/// </summary>
struct phone
{
	int city;
	int phone_station;
	int phone_abonent;

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