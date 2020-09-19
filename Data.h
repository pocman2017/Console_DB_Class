#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Данные ФИО, Дата, Адрес

struct Initials{
	string surname,
		name,
		partinymeric;
};
struct Date {
	int day,
		month,
		year;
};
struct Address {
	string city;
	int home;
};
// Прототип класса
class Data
{
private:
	Initials initials;
	Date date;
	Address address;
public:
	// Обязательные методы класса
	Data();// Конструктор без параметров
	Data(Initials initials_, Date date_, Address addres_);//Конструктор с параметрами
	~Data(); // Деструктор
	// Необязательные методы класса(для выполнения задания)
	void Print();
	void DataEntry(Initials initials_, Date date_, Address addres_);
	// Вывод данных (полей) из класса
	Initials GetInitials() { return initials; };
	Date GetDate() { return date; };
	Address GetAddress() { return address; };
	// Перегрузка оператора
	Data& operator = (Data d_o);
};
