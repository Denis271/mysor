#include<iostream> 
using namespace std;
int main(){
int sum=0;
int count,number;
cout<<"Введите количество чисел\n";
cin>>count;
for(int i=0; i<count; i++)
{
    cout<<"Введите число\n";
    cin>>number;
    sum += number;
}
cout<< "Сумма: " << sum;
 
return 0;
}