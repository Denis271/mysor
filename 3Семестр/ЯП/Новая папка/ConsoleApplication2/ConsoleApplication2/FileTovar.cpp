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
// ������ ��������� � ����
static void saveTovar()
{
    cout << "�������� ������: "; cin >> tovar_data.name;
    cout << "���� ������: "; cin >> tovar_data.price;
    fstream fs;
    fs.open(filename_tovar, fstream::in | fstream::out | fstream::app); //��������� �� ���������� � ������ � ������ ����������
    fs << "\n" << tovar_data.name + ";" + tovar_data.price;
    fs.close(); // ������� ����
}

// ������ ��������� � ����
static void loadTovar()
{
    string text;
    fstream fs;
    int count = 0;
    fs.open(filename_tovar, fstream::in | fstream::out | fstream::app);
    cout << setw(4) << "�|" << setw(21) << "�������� ������|" << setw(21) << "���� ������|" << endl;

    while (!fs.eof())
    {
        count++;
        fs >> text;
        istringstream str(text);
        getline(str, tovar_data.name, ';');
        getline(str, tovar_data.price, ';');
        cout << setw(3) << count << "|" << setw(20) << tovar_data.name << "|" << setw(20) << tovar_data.price << endl;

    }
    fs.close(); // ������� ����

}