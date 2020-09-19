#pragma once
#include"Data.h"

// Прототипы функций
void DataEntry(Data* (&d), int& n);// Ввод данных вручную
void DataReading(Data* (&d), int& n, string filename);// Чтение из файла
void Print(Data* d, int n); // Вывод на консоль
void DataChange(Data* d, int n); // Изменить данные
void Copy(Data* d_n, Data* d_o, int n); // копия данных массива
void AddData(Data* (&d), int& n); // Добавление данных
void DeleteData(Data* (&d), int& n); // Удаление данных
void SortingData(Data* d, int n); // Сортировка
void SaveData(Data* d, int n, string filename); // Сохранение данных

