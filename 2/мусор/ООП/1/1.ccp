/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int count;
    double price_copybook;
    double price_cover;
    double symma;
    
    std::cout << "Введите количество: ";
    std::cin >> count;
    
    std::cout << "Введите цену тетради: ";
    std::cin >> price_copybook;
    
    std::cout << "Введите цену обложки: ";
    std::cin >> price_cover;
    
    symma = (price_copybook + price_cover) * count;
    
    std::cout << "Итого: " << symma << "р.";
    return 0;
}
