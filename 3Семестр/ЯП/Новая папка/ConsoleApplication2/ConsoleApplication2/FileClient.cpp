#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
struct client
{
    string FIO;
    string tlf;
    int age;
};

    const string filename = "client.dat";
// запись структуры в файл
static void saveClient()
{
    struct client client_data;
    cout << "Ваше ФИО: "; cin >> client_data.FIO;
    cout << "Ваш возраст: "; cin >> client_data.age;  
    cout << "Ваш телефон: "; cin >> client_data.tlf;
    ofstream outFile(filename, std::ios::app);
    outFile.write((char*)&client_data, sizeof(client));
    outFile.close(); // закрыть файл
}

// чтения структуры в файл
static void loadClient()
{
    ifstream inF(filename, ios::in);
    while (!inF.eof())
    {
     
    }
    inF.close(); // закрыть файл
}