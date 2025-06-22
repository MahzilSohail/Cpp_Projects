#include<iostream>
using namespace std;
int main(){
    int pin1=1234, balance=50000;
    int pin2;
    cout<<"Welcome to ATM!\n";
    cout<<"Enter your pin : ";
    cin>>pin2;
    if(pin2 != pin1){
        cout<<"Invalid pin";
    }
    int choice;
    do{
    cout<<"ATM System\n";
    cout<<"1. Check Balance\n";
    cout<<"2. Withdraw\n";
    cout<<"3. Deposit\n";
    cout<<"4. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Your balance is "<<balance<<endl;
            break;
        case 2:
            int withdraw;
            cout<<"Enter the amount to withdraw: ";
            cin>>withdraw;
            if(withdraw<balance && withdraw>0){
                balance -= withdraw;
            }else{
                cout<<"Your amount is invalid! enter valid amount";
            }
            cout<<"Your remaining balance is: "<<balance<<endl;
            break;
        case 3:
            int deposit;
            cout<<"Enter the amount to deposit: ";
            cin>>deposit;
            if(deposit>0){
                balance += deposit;
            }else{
                cout<<"Your amount is invalid! enter valid amount";
            }
            cout<<"Your remaining balance is: "<<balance<<endl;
            break;
        case 4:
            cout<<"Thank you for using ATM!";
            break;
        default:
            cout<<"Invalid choice!";
    }
    }while(choice!=4);
    return 0;
}