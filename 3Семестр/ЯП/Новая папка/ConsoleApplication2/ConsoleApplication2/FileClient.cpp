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
// ������ ��������� � ����
static void saveClient()
{
    struct client client_data;
    cout << "���� ���: "; cin >> client_data.FIO;
    cout << "��� �������: "; cin >> client_data.age;  
    cout << "��� �������: "; cin >> client_data.tlf;
    ofstream outFile(filename, std::ios::app);
    outFile.write((char*)&client_data, sizeof(client));
    outFile.close(); // ������� ����
}

// ������ ��������� � ����
static void loadClient()
{
    ifstream inF(filename, ios::in);
    while (!inF.eof())
    {
     
    }
    inF.close(); // ������� ����
}