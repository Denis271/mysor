#include <string>
#include <iostream>
#include "MenuIndex.cpp"
using namespace std;

void Menu() {
	string  menuName = "index";
	while (true) {
		if (menuName == "index")
		{
			customSwitchMenuIndex();
		}
	}
}