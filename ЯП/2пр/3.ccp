/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int Max;
    int lenght;
    cout<<"Введите количество чисел";
    std::cin >> lenght;
    int NumberArray[lenght];
    for (int i = 0; i < lenght; i++) {
        cout<<"Введите число";
        std::cin >> NumberArray[lenght];
        if(i == 0){
           Max =  NumberArray[lenght];
        }else if(Max < NumberArray[lenght]){
           Max = NumberArray[lenght];
        }
    }
    cout<<"Max число" << Max;
    return 0;
}
