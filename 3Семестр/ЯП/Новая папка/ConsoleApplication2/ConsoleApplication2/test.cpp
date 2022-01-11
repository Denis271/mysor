#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <sstream>
#include <conio.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024
#define ERR_OPEN_FILE 1
using namespace std;

string open_line_tabl(int n_line, int n_tab) {
	string path;
	switch (n_tab) {
	case 1:
		path = "product.txt";
		break;
	case 2:
		path = "publication.txt";
		break;
	case 3:
		path = "sales_history.txt";
		break;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app); //параметры на считывания и записи и отмена перезаписи
	if (!fs.is_open())
	{
		cout << "ошибка открытия файла" << endl;
	}
	else
	{
		string text;
		for (int i = 0; i < n_line; i++)
		{
			text = "";
			fs >> text;

		}

		return text;
	}
	fs.close();
}
void open_table(int a) { //таблицы
	string path;
	switch (a) {
	case 1:
		path = "product.txt";
		break;
	case 2:
		path = "publication.txt";
		break;
	case 3:
		path = "sales_history.txt";
		break;
	}

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app); //параметры на считывания и записи и отмена перезаписи
	if (!fs.is_open())
	{
		cout << "ошибка открытия файла" << endl;
	}
	else
	{
		string text;
		system("cls");
		if (a == 1) //таблица товаров
		{
			cout << setw(44) << "Таблица товаров:" << endl;
			string id_line;
			string name_book;
			string avtor;
			string genre;
			string money;
			int n = 0;
			cout << setw(4) << "№|" << setw(21) << "Наименование|" << setw(21) << "Автор|" << setw(16) << "Жанр|" << setw(11) << "Стоимость|" << endl;
			while (!fs.eof())
			{
				text = "";
				fs >> text;
				istringstream str(text);
				getline(str, id_line, ';');
				getline(str, name_book, ';');
				getline(str, avtor, ';');
				getline(str, genre, ';');
				getline(str, money);
				n++;
				cout << setw(3) << n << "|" << setw(20) << name_book << "|" << setw(20) << avtor << "|" << setw(15) << genre << "|" << setw(10) << money << "|" << endl;
			}
		}





		if (a == 2)//таблица издателей издатель | email | Id книги |
		{
			cout << setw(44) << "Таблица издателей:" << endl;
			string publication;
			string email;
			string id_book;
			string name_book;
			int n = 0;
			cout << setw(4) << "№|" << setw(21) << "Издатель|" << setw(21) << "Email|" << setw(16) << "Книга|" << endl;
			while (!fs.eof())
			{
				text = "";
				fs >> text;
				istringstream str(text);
				getline(str, publication, ';');
				getline(str, email, ';');
				getline(str, id_book, ';');
				n++;

				fstream fs2; //вывод названия книги по id из файла издателей
				fs2.open("product.txt", fstream::in | fstream::out | fstream::app);

				if (!fs2.is_open())
				{
					cout << "ошибка открытия файла" << endl;
				}
				else
				{
					string id_line;
					string name_bookP;
					string avtor;
					string genre;
					string money;
					string text_name_book_id;
					while (!fs2.eof()) {
						text_name_book_id = "";
						fs2 >> text_name_book_id;
						istringstream str2(text_name_book_id);
						getline(str2, id_line, ';');
						getline(str2, name_bookP, ';'); // имя книги
						getline(str2, avtor, ';');
						getline(str2, genre, ';');
						getline(str2, money);
						name_book = "Ошибка";
						if (id_book == id_line)
						{
							name_book = name_bookP;
							break;
						}
					}
				}

				cout << setw(3) << n << "|" << setw(20) << publication << "|" << setw(20) << email << "|" << setw(15) << name_book << "|" << endl;
				fs2.close();
			}
		}







		if (a == 3)//таблица продаж номер продажи | книга | издатель | количество продаж | сумма прибыли
		{
			cout << setw(44) << "Таблица издателей:" << endl;
			string Nsales;
			string name_book;
			string publication;
			string kolvo;
			string money;
			int n = 0;
			cout << setw(4) << "№|" << setw(21) << "Книга|" << setw(21) << "Издатель|" << setw(16) << "Кол-во продаж|" << setw(16) << "Сумма прибыли | " << endl;
				while (!fs.eof())
				{
					text = "";
					fs >> text;
					istringstream str(text);
					getline(str, Nsales, ';');
					getline(str, name_book, ';');
					getline(str, publication, ';');
					getline(str, kolvo, ';');
					getline(str, money);
					cout << setw(3) << Nsales << "|" << setw(20) << name_book << "|" << setw(20) << publication << "|" << setw(15) << kolvo << "|" << setw(10) << money << " руб.|" << endl;
				}
		}





	}
	fs.close();
}
void menu() {
	cout << "Открыть товары - 1" << endl;
	cout << "Открыть издателей - 2" << endl;
	cout << "Открыть историю продаж - 3" << endl;
}
int menu2() {
	int b, a;
	cout << "Добавть - 1" << endl;
	cout << "Удалить строку - 2" << endl;
	cout << "Назад - 0" << endl;
	cin >> b;
	return b;
}
void add(int a) {

	string path;
	switch (a) {
	case 1:
		path = "product.txt";
		break;
	case 2:
		path = "publication.txt";
		break;
	case 3:
		path = "sales_history.txt";
		break;
	}
	string sep = ";";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app); //параметры на считывания и записи и отмена перезаписи
	if (!fs.is_open())
	{
		cout << "ошибка открытия файла" << endl;
	}
	else
	{
		system("cls");
		string text;
		if (a == 1)
		{
			string name, avtor, genre, money;
			string num = "3";//----------------------—
			cout << "Введите название книги:";
			cin >> name;
			cout << "Введите автора:";
			cin >> avtor;
			cout << "Введите жанр:";
			cin >> genre;
			cout << "Введите стоимость:";
			cin >> money;
			text = num + sep + name + sep + avtor + sep + genre + sep + money;
		}
		if (a == 2)
		{
			string publication, email, id_book, Nline_tab;
			cout << "Введите издательство:";
			cin >> publication;
			cout << "Введите Email издательства:";
			cin >> email;
			open_table(1);
			cout << "Выберите книгу.Введите номер строки из таблицы выше:";
			cin >> Nline_tab;
			text = publication + sep + email + sep + Nline_tab;
		}
		if (a == 3)
		{
			string Nsales;//><
			string name_book;//><
			string publication;//><
			string kolvo_sales;
			string Smoney;
			int NlineBook, kolvo;


			fstream fs2; //узнаем следующий id
			fs2.open("sales_history.txt", fstream::in | fstream::out | fstream::app);
			if (!fs2.is_open())
			{
				cout << "ошибка открытия файла" << endl;
			}
			else
			{
				string id_line, ttext;

				while (!fs2.eof()) {
					ttext = "";
					fs2 >> ttext;
					istringstream str2(ttext);
					getline(str2, id_line, ';');
				}
				int NewIdHisInt = stoi(id_line);
				NewIdHisInt++;
				Nsales = to_string(NewIdHisInt);//новый id
			}
			fs2.close();




			open_table(1);//вывод таблицы книг
			cout << "Выберите книгу из таблицы выше: ";
			cin >> NlineBook;//выбор книги
			name_book = open_line_tabl(NlineBook, 1);//строка с нужной книгой
			string id_book, null, money;
			istringstream str2(name_book);

			getline(str2, id_book, ';'); //id книги
			getline(str2, name_book, ';'); // имя книги
			getline(str2, null, ';'); //
			getline(str2, null, ';'); //
			getline(str2, money, ';'); // стоимость книги




			fstream fs3; //узнаем наименование издательства по книге
			fs3.open("publication.txt", fstream::in | fstream::out | fstream::app);
			if (!fs3.is_open())
			{
				cout << "ошибка открытия файла" << endl;
			}
			else
			{
				string st1, st2, st3, ttext;
				while (!fs3.eof()) {
					ttext = "";
					fs3 >> ttext;
					istringstream str2(ttext);
					getline(str2, st1, ';');
					getline(str2, st2, ';');
					getline(str2, st3, ';');
					if (st3 == id_book)
					{
						publication = st1;

						break;
					}
					else
					{
						publication = "Нету издателя!!!";
					}
				}


			}
			fs3.close();

			cout << "Введите количество проданных книг: ";
			cin >> kolvo;

			int money1 = stoi(money);
			money1 = money1 * kolvo;
			kolvo_sales = to_string(kolvo);//колличество проданных книг
			Smoney = to_string(money1);//выручка
			text =
				Nsales + sep + name_book + sep + publication + sep + kolvo_sales + sep + Smoney;

		}
		fs << "\n" << text;
	}
	fs.close();
}
void delete_line(int a) {
	string path;
	switch (a) {
	case 1:
		path = "product.txt";
		break;
	case 2:
		path = "publication.txt";
		break;
	case 3:
		path = "sales_history.txt";
		break;
	}
	const char* delete_name = path.c_str();

	int NLine;
	cout << "Введите номер строки для удаления: ";
	cin >> NLine;
	string text = "";
	string text2 = "";
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (!fs.is_open())
	{
		cout << "ошибка открытия файла" << endl;
	}
	else
	{


		int num = 1;
		while (!fs.eof())
		{
			fs >> text;
			if (num == NLine)
			{
			}
			else
			{
				if (num == 1)
				{
					text2 = text;
				}
				else {
					text2 = text2 + "\n" + text;
				}
			}
			num++;

		}


	}
	fs.close();
	remove(delete_name);
	switch (a) {
	case 1:
		path = "product.txt";
		break;
	case 2:
		path = "publication.txt";
		break;
	case 3:
		path = "sales_history.txt";
		break;
	}

	fstream fs2;
	fs2.open(path, fstream::in | fstream::out | fstream::app); //параметры на считывания и записи и отмена перезаписи
	if (!fs2.is_open())
	{
		cout << "ошибка открытия файла" << endl;
	}
	else
	{
		fs2 << text2;
	}

}

static int mainda()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int b, a = 0;

	while (a < 9)
	{


		if (a == 0) //меню 1
		{
			menu();
			cin >> a;
		}




		if (a == 1) // таблица товаров
		{
			open_table(a);
			b = menu2();
			switch (b) {
			case 0:
				a = 0;
				system("cls");
				break;
			case 1:
				add(a); //добавление
				break;
			case 2:
				delete_line(a);
				break;
			}
		}




		if (a == 2) //меню 1
		{
			open_table(a);
			b = menu2();
			switch (b) {
			case 0:
				a = 0;
				system("cls");
				break;
			case 1:
				add(a); //добавление
				break;
			case 2:
				delete_line(a);
				break;
			}
		}




		if (a == 3) //меню 1
		{
			open_table(a);
			b = menu2();
			switch (b) {
			case 0:
				a = 0;
				system("cls");
				break;
			case 1:
				add(a); //добавление
				break;
			case 2:
				delete_line(a);
				break;
			}
		}

	}




	return 0;


}