#define _CRT_SECURE_NO_DEPRECATE
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
using namespace std;
static struct tovar
{
    string name;
    string price;
};
static tovar tovar_data;
const string filename_tovar = "tovar.txt";
// запись структуры в файл
static void saveTovar()
{
    cout << "Название товара: "; cin >> tovar_data.name;
    cout << "Цена товара: "; cin >> tovar_data.price;
    fstream fs;
    fs.open(filename_tovar, fstream::in | fstream::out | fstream::app); //параметры на считывания и записи и отмена перезаписи
    fs << "\n" << tovar_data.name + ";" + tovar_data.price;
    fs.close(); // закрыть файл
}

// чтения структуры в файл
static void loadTovar()
{
    string text;
    fstream fs;
    int count = 0;
    fs.open(filename_tovar, fstream::in | fstream::out | fstream::app);
    cout << setw(4) << "№|" << setw(21) << "Название товара|" << setw(21) << "Цена товара|" << endl;

    while (!fs.eof())
    {
        count++;
        fs >> text;
        istringstream str(text);
        getline(str, tovar_data.name, ';');
        getline(str, tovar_data.price, ';');
        cout << setw(3) << count << "|" << setw(20) << tovar_data.name << "|" << setw(20) << tovar_data.price << endl;

    }
    fs.close(); // закрыть файл

}

// поиск  из файла
static void findTovarName()
{
    string text;
    fstream fs;
    int count = 0;

    string search;
    cout << "Укажите название товара который вы ищете "; cin >> search;

    fs.open(filename_tovar, fstream::in | fstream::out | fstream::app);
    cout << setw(4) << "№|" << setw(21) << "Название товара|" << setw(21) << "Цена товара|" << endl;

    while (!fs.eof())
    {
        count++;
        fs >> text;
        istringstream str(text);
        getline(str, tovar_data.name, ';');
        getline(str, tovar_data.price, ';');
        if (tovar_data.name.find(search) != std::string::npos) {
            cout << setw(3) << count << "|" << setw(20) << tovar_data.name << "|" << setw(20) << tovar_data.price << endl;
        }
       

    }
    fs.close(); // закрыть файл

}