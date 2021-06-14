/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
// задание 1
int int1 = 151;
int int2 = 11;
if(int1 > int2){
    cout << "Max=" << int1 << "\n";
    cout<<"Min=" << int2 << "\n";
}
else{
cout<<"Max=" << int2 << "\n";
cout<<"Min=" << int1 << "\n";
}
// задание 2
int intUser1, intUser2, intUser3;
cout<<"Введите первое число";
std::cin >> intUser1;
cout<<"Введите второе число";
std::cin >> intUser2;
cout<<"Введите третье число";
std::cin >> intUser3;
int arrIntUser[3] = {intUser1,intUser2,intUser3};
int maxUser = 0;
int minUser = 0;
for (int i = 0; i < 3; i++) {
cout<<"arrIntUser-" << arrIntUser[i] << "\n";
if(maxUser < arrIntUser[i] || !maxUser){
maxUser = arrIntUser[i];
}
if(minUser > arrIntUser[i] || !minUser){
minUser = arrIntUser[i];
}
}

cout<<"maxUser-" << maxUser << "\n";
cout<<"minUser-" << minUser << "\n";
// задание 3
int number[3] = {5, 11, 15};
for (int i = 0; i < 3; i++) {
if(number[i] >= 1 && number[i] <= 7){
cout<<"Число находится в отрезке (1,7)-"
<< number[i] << "\n";
}
}
// задание 4
int number2[3] = {71, 51, -41};
for (int i = 0; i < 3; i++) {
if(number2[i] >= 0){
cout<<"Положительное число в квадрате"
<< number2[i] * number2[i] << "\n";
}
}
// задание 5
int Number;
cout<<"Введите  число";
std::cin >> Number;
if(Number % 2 == 0){
    cout<<"Указанное число" << Number << " является четным \n";
}else{
    cout<<"Указанное число" << Number << " является  не четным\n";
}
// задание 6
int number3 = 1111;
float numberM = number3;
float number3Char[4];
for (int i = 0; i < 4; i++) {
number3Char[i] = round (numberM / 10 - int(numberM / 10));
numberM = int(numberM / 10);
cout<< number3Char[i] << "\n";
}
if(number3Char[0] + number3Char[1] == number3Char[2] + number3Char[3]){
cout<<"Условие повпадает \n";
}
else{
cout<<"Условие не совпадает \n";
}
//задание 7
int x,y,z;
cout<<"Введите число \n";
 std::cin >> x;
 cout<<"Введите число \n";
 std::cin >> y;
 cout<<"Введите число \n";
 std::cin >> z;
 int k=1;
if (x>y+z)
  k=0; 
else
     if (y>x+z)
       k=0; 
     else
          if (z>x+y)
            k=0;
if(k){
    cout<<"Треугольник существует \n";
} else{
    cout<<"Треугольник не существует \n";
}
//задание 8
int NMoubt;
cout<<"Введите цифру месяца \n";
std::cin >> NMoubt;
if(NMoubt > 0 && NMoubt < 12){
    switch(NMoubt){
        case 1:
            cout<<"Январь \n";
            break;
        case 2:
            cout<<"Февраль \n";
            break;
        case 3:
            cout<<"Март \n";
            break;
        case 4:
            cout<<"Апрель \n";
            break;
        case 5:
            cout<<"Май \n";
            break;
        case 6:
            cout<<"Июнь \n";
            break;
        case 7:
            cout<<"Июль \n";
            break;    
        case 8:
            cout<<"Август \n";
            break;
        case 9:
            cout<<"Сентябрь \n";
            break;
          case 10:
            cout<<"Октябрь \n";
            break;
                  case 11:
            cout<<"Ноябрь \n";
            break;
        case 12:
            cout<<"Декабрь \n";
            break;
    }
}else{
    cout<<"Некореткно указана цифра месяца! \n";
}
getchar();
return 0;
}
