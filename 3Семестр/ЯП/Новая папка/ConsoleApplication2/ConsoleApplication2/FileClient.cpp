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
static struct client
{
    string FIO;
    string tlf;
    string age;
};
static client client_data;
    const string filename = "client.txt";
// ������ ��������� � ����
static void saveClient()
{
    cout << "���� ���: "; cin >> client_data.FIO;
    cout << "��� �������: "; cin >> client_data.age;  
    cout << "��� �������: "; cin >> client_data.tlf;
    fstream fs;
    fs.open(filename, fstream::in | fstream::out | fstream::app); //��������� �� ���������� � ������ � ������ ����������
    fs << "\n" << client_data.FIO + ";" + client_data.age + ";" + client_data.tlf;
    fs.close(); // ������� ����
}

// ������ ��������� � ����
static void loadClient()
{
    string text;
    fstream fs;
    int count = 0;
    fs.open(filename, fstream::in | fstream::out | fstream::app);
    cout << setw(4) << "�|" << setw(21) << "���|" << setw(21) << "�������|" << setw(16) << "�������|" << endl;
    
        while (!fs.eof())
        {
            count++;
            fs >> text;
            istringstream str(text);
            getline(str, client_data.FIO, ';');
            getline(str, client_data.age, ';');
            getline(str, client_data.tlf, ';');
            cout << setw(3) << count << "|" << setw(20) << client_data.FIO << "|" << setw(20) << client_data.age << "|" << setw(15) << client_data.tlf << endl;

        }
        fs.close(); // ������� ����

}