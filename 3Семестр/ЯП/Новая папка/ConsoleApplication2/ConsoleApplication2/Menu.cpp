
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
#include "FileClient.cpp";
#include "FileTovar.cpp";
using namespace std;

void menuMainClient();
void menuMain();
void menuMainTovar();
void menuMainPurchase();

static void menuMain() {
	system("cls");
	string index;
	std:cout << "1-посмотреть клиентов\n";
	std::cout << "2-посмотреть товары\n";
	std::cout << "3-посмотреть покупки\n";
	std::cin >> index;
	if (index == "1") {
		menuMainClient();
	}
	if (index == "2") {
		menuMainTovar();
	}
	if (index == "3") {
		menuMainPurchase();
	}
	 
}

static void menuMainTovar() {
	system("cls");
	string index;
	std:cout << "1-добавить товар\n";
	std::cout << "2-отобразить товары\n";
	std::cout << "3-назад\n";
	std::cin >> index;
	if (index == "1") {
		saveTovar();
		menuMainTovar();
	}
	if (index == "2") {
		loadTovar();
		string index;
		std::cout << "1-назад\n";
		std::cin >> index;
		if (index == "1") {
			menuMainTovar();
		}
	}
	if (index == "3") {
		menuMain();
	}

}

static void menuMainClient() {
	system("cls");
	string index;
std:cout << "1-добавить клиента\n";
	std::cout << "2-отобразить клиентов\n";
	std::cout << "3-назад\n";
	std::cin >> index;
	if (index == "1") {
		saveClient();
		menuMainClient();
	}
	if (index == "2") {
		loadClient();
		string index;
		std::cout << "1-назад\n";
		std::cin >> index;
		if (index == "1") {
			menuMainClient();
		}

	}
	if (index == "3") {
		menuMain();
	}

}

static void menuMainPurchase() {
	system("cls");
	string index;
	std:cout << "1-добавить покупку\n";
	std::cout << "2-отобразить покупку\n";
	std::cout << "3-назад\n";
	std::cin >> index;
	if (index == "1") {

	}
	if (index == "2") {

	}
	if (index == "3") {
		menuMain();
	}

}