#include <string>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <sstream>
#include <conio.h>
#include <algorithm>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

//задание 1
int a, b, num_task = 0;




while (num_task < 8)
{
std::cout « "Введите номер задачи 1-8: ";
std::cin » num_task;
if (num_task == 1) //Задача 1
{
std::cout « "Задача 1 \n";
int a = 2;
while (a < 101)
{
std::cout « a « "\n";
a = a + 2;
}
}
if (num_task == 2) //Задача 2
{
std::cout « "Задача 2 \n";
int a = 1;
while (a < 101)
{
std::cout « a « "\n";
a = a * 2;
}
}
if (num_task == 3) //Задача 3
{
std::cout « "Задача 3 \n";
int i;
printf("арифметический цикл \n");
for (i = 1950; i < 2020; i++)
if (i % 400 == 0 || (i % 4 == 0 && i % 100))

printf("%d\n", i);
printf("итерационный цикл \n");
for (i = 1952; i < 2020; i += 4)
printf("%d\n", i);
}
if (num_task == 4) //Задача 4
{
std::cout « "Задача 4 \n";
int i,n,w;
w = 2;
printf("Введите N:");
std::cin » n;
for (i = 1; i < n; i++)
{
w = w * 2;
}
std::cout « "2^N = " « w « "\n";

}
if (num_task == 5) //Задача 5
{
std::cout « "Задача 5 \n";
int a, sum;
sum = 0;
printf("Введите натуральное число:");
std::cin » a;
while (a > 0)
{
sum = sum + (a % 10);
a /= 10;
}
std::cout « "сумма цифр: " « sum « "\n";
}
if (num_task == 6) //Задача 6
{
int j,i,n, n1, n2, r;
r = 1;
std::cout « "Задача 6 \n";
for ( i = 0; i < 999999; i++)
{
n1 = 0;
n2 = 0;
n = i;
j = 0;
while (n > 0)
{
if (j<3)
{
n1 = n1 + (n % 10);
n /= 10;
}
if (j > 2)
{
n2 = n2 + (n % 10);
n /= 10;
}
j++;
}
if (n1==n2)
{
r++;

}

}
std::cout « r « "\n";
std::cout « "Количество счастливых билетов =" « r;
}
if (num_task == 7) //Задача 7
{
int i, j, num1, num2, r1, r2,r3,r4, r=0;
for ( i = 0; i < 24; i++)
{
for ( j = 0; j < 60; j++)
{
num1 = i;
num2 = j;
r1 = num1 / 10;
r2 = num1 %10;
r3 = num2 % 10;
r4 = num2 / 10;
if ((r1==r3) && (r2==r4))
{
std::cout « r1 « r2 « ':' « r4 « r3 « "\n";
r++;
}
}
}
std::cout « "Количество счастливых билетов =" « r;
}
std::cout « "для выхода введите любое число больше 8 \n";
}

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
 

 
 
 
