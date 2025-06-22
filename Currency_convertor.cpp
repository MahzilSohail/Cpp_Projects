#include<iostream>
using namespace std;
int main(){
    float amount, result;
    int choice;
    cout<<"Enter your amount in PKR (Pakistani Rupees): ";
    cin>>amount;
    cout<<"--Currency Convertor--\n";
    cout<<"1. PKR to USD\n2. PKR to EUR\n3. PKR to GBP\n4. PKR to SAR\n5. PKR to AED\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice) {
        case 1: 
        result = amount / 278; 
        break;    
        case 2: 
        result = amount / 300; 
        break;
        case 3: 
        result = amount / 350; 
        break;   
        case 4: 
        result = amount / 74; 
        break;
        case 5: 
        result = amount / 76; 
        break;
        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    cout << "Converted amount: " << result << endl;
    return 0;

}