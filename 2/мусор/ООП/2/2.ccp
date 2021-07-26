/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

double checkNumber(double number) {
       double checkNumber = number - (int)number;
       if(checkNumber == 0 && (int)number % 2 == 0){
            return number;
       } 
       return 0;
    }

int main()
{
  
    double a;
    double b;
    double c;
    
    double symma;
    
    std::cout << "Введите a: ";
    std::cin >> a;
    
    std::cout << "Введите b: ";
    std::cin >> b;
    
    std::cout << "Введите c: ";
    std::cin >> c;
    
    symma = symma + checkNumber(a);
    symma = symma + checkNumber(b);
    symma = symma + checkNumber(c);
    
    std::cout << "Сумма: " << symma;
 
    
 
    return 0;
}
