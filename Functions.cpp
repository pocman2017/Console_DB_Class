#include "Functions.h"

// Описание функций
void DataEntry(Data* (&d), int& n)// Ввод данных вручную
{
	Initials initials; // Временные переменные
	Date date;
	Address address;

	cout << "Введите размер массива: ";
	cin >> n;
	// Выделяем память для массива данных
	d = new Data[n];
	// Вводим данные
	for (int i = 0; i < n; n++)
	{
		cout << "Введите ФИО: ";
		cin >> initials.surname >> initials.name >> initials.partinymeric;
	
		cout << "Введите дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << "Введите адрес: ";
		cin >> address.city >> address.home;

		// Добавляем новые данные в элемент массива объект класса
		d[i].DataEntry(initials, date, address);
		cout << " --------------------------------------\n";
	}
}
void DataReading(Data* (&d), int& n, string filename)// Чтение из файла
{
	// Создадим поток для чтения
	ifstream reading(filename);
	if (reading)
	{
		Initials initials; // Временные переменные
		Date date;
		Address address;
		reading >> n;

		// Выделяем память для массива данных
		d = new Data[n];
		// Считываем данные
		for (int i = 0; i < n; i++)
		{
			reading >> initials.surname >> initials.name >> initials.partinymeric;
			reading >> date.day >> date.month >> date.year;
			reading >> address.city >> address.home;
			// Добавляем новые данные в элемент массива объект класса
			d[i].DataEntry(initials, date, address);
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}
void Print(Data* d, int n) // Вывод на консоль
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные № " << i + 1 << endl;

		d[i].Print();
		cout << " ---------------------------------\n";
	}
}
void DataChange(Data* d, int n) // Изменить данные
{

	Initials initials; // Временные переменные
	Date date;
	Address address;
	int _n;
	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		cout << "Введите новые ФИО: ";
		cin >> initials.surname >> initials.name >> initials.partinymeric;

		cout << "Введите новую дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << "Введите адрес: ";
		cin >> address.city >> address.home;
		// Добавляем новые данные в элемент массива объект класса
		d[_n].DataEntry(initials, date, address);
	}
	else
		cout << "Неверно введен номер!" << endl;
}
void Copy(Data* d_n, Data* d_o, int n) // копия данных массива
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}
void AddData(Data* (&d), int& n) // Добавление данных
{
	Initials initials; // Временные переменные
	Date date;
	Address address;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите ФИО: ";
	cin >> initials.surname >> initials.name >> initials.partinymeric;

	cout << "Введите дату: ";
	cin >> date.day >> date.month >> date.year;

	cout << "Введите адрес: ";
	cin >> address.city >> address.home;
	// Добавляем новые данные в элемент массива объект класс
	d[size].DataEntry(initials, date, address);

	cout << "Данные добавлены!" << endl;

	delete[] buf;
}
void DeleteData(Data* (&d), int& n) // Удаление данных
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Copy(buf, d, n);
		int q = 0;
		n--;
		// Выделяем новую память
		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			if (i != _n)
			{
				d[q] = buf[i];
				q++;
			}
		}
		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введен неверно!" << endl;

	delete[]buf;
}
void SortingData(Data* d, int n) // Сортировка
{
	Data buf; // Временные переменные
	int numOfSorted = 0;
	// Сортировка пузырьком по фамилии

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// Усдовие сортировки
			if (d[i].GetInitials().surname > d[j].GetInitials().surname)
			{
				// Перестановка
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSorted++;
			}
		}
	}
	cout << "Данные отсортированы! Количество перестановок: " << numOfSorted << endl;
}
void SaveData(Data* d, int n, string filename) // Сохранение данных
{
	ofstream record(filename);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().partinymeric << endl;
			record << d[i].GetDate().day << " " << d[i].GetDate().month << " " << d[i].GetDate().year << endl;
			record << d[i].GetAddress().city << " " << d[i].GetAddress().home;

			if (i < n - 1)
				record << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	cout << "Данные сохранены в файл - " << filename << endl;

	record.close();
}


