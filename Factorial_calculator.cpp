#include<iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter the number to calculate it`s factorial: ";
    cin>>num;
    int factorial=1;
    for (int i=1; i<=num; i++) {
        factorial=factorial*i;
    }
    cout<<"The factorial of "<<num<<" is "<<factorial;

    return 0;
}