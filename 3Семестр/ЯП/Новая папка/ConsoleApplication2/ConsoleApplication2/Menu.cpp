
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
#include "libs.cpp";
using namespace std;

void menuMainClient();
void menuMain();
void menuMainTovar();


static void menuMain() {
	system("cls");
	string index;
	std:cout << "1-посмотреть клиентов\n";
	std::cout << "2-посмотреть товары\n";
	std::cout << "3-выйти\n";
	std::cin >> index;
	if (index == "1") {
		menuMainClient();
	}
	if (index == "2") {
		menuMainTovar();
	}
	if (index == "3") {
		exit(0);
	}
}

static void menuMainTovar() {
	system("cls");
	string index;
	std:cout << "1-добавить товар\n";
	std::cout << "2-отобразить товары\n";
	std::cout << "3-поиск товара по наименованию\n";
	std::cout << "4-назад\n";
	std::cin >> index;
	if (index == "1") {
		saveTovar();
		menuMainTovar();
	}
	if (index == "2") {
		loadTovar();
		string index;
		std::cout << "1-назад\n";
		std::cout << "2-удалить товар\n";
		std::cin >> index;
		if (index == "1") {
			menuMainTovar();
		}
		if (index == "2") {
			deleteRows("tovar.txt");
			menuMainClient();
		}
	}
	if (index == "3") {
		findTovarName();
		std::cout << "1-назад\n";
		std::cin >> index;
		if (index == "1") {
			menuMainTovar();
		}
	}
	if (index == "4") {
		menuMain();
	}

}

static void menuMainClient() {
	system("cls");
	string index;
	std:cout << "1-добавить клиента\n";
	std::cout << "2-отобразить клиентов\n";
	std::cout << "3-поиск клиентов по ФИО\n";
	std::cout << "4-назад\n";
	std::cin >> index;
	if (index == "1") {
		saveClient();
		menuMainClient();
	}
	if (index == "2") {
		loadClient();
		string index;
		std::cout << "1-назад\n";
		std::cout << "2-удалить клиента\n";
		std::cin >> index;
		if (index == "1") {
			menuMainClient();
		}
		if (index == "2") {
			deleteRows("client.txt");
			//menuMainClient();
		}

	}
	if (index == "3") {
		findClientFIO();
		std::cout << "1-назад\n";
		std::cin >> index;
		if (index == "1") {
			menuMainClient();
		}
	}
	if (index == "4") {
		menuMain();
	}

}