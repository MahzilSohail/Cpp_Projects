#include<iostream>
using namespace std;
int main(){
    float num1,num2;
    int choice;
    cout<<"Enter two numbers: \n";
    cin>>num1>>num2;
    cout<<"Select option:\n1.Addition.\n2.Subtraction.\n3.Multiplication.\n4.Division.\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Your answer: "<<num1+num2<<endl;
        break;
        case 2:
        cout<<"Your answer: "<<num1-num2<<endl;
        break;
        case 3:
        cout<<"Your answer: "<<num1 * num2<<endl;
        break;
        case 4:
        cout<<"Your answer: "<<num1 / num2<<endl;
        break;
        default:
        cout<<"Invalid choice";

    }

    return 0;
}