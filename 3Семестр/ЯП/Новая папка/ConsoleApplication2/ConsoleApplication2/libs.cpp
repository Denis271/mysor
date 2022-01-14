#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// удалить строку
static void deleteRows(string filename) {
    int index;
    fstream fs;
    int row = 1;
    string text = "";

    cout << "”кажите удал€емую строчку "; cin >> index;
    fs.open(filename, fstream::in | fstream::out);
    while (!fs.eof()) {
        string textRow = "";
        fs >> textRow;
        if (row != index) {
            if (text != "") {
                text = text + "\n" + textRow;
            }
            else {
                text = textRow;
            }

        }
        row++;
    }
    fs.close();
    ofstream fout;
    fout.open(filename);
    fout << text;
    fout.close();
}