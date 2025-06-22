#include <iostream>
#include <iomanip>
using namespace std;

bool isLeap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1: return 31;
        case 2: return isLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
        default:return 0;
    }
}

int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int day = 1;

    int h = (day + 13*(month + 1)/5 + K + K/4 + J/4 + 5*J) % 7;
    return (h + 6) % 7; 
}

void printCalendar(int month, int year) {
    const string months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    
    cout << "\n  " << months[month - 1] << " " << year << endl;
    cout << "  Su Mo Tu We Th Fr Sa\n";

    int days = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    int current = 1;
    for (int i = 0; i < startDay; ++i)
        cout << "   ";

    for (int i = startDay; i < 7; ++i)
        cout << setw(3) << current++;

    cout << endl;
    while (current <= days) {
        for (int i = 0; i < 7 && current <= days; ++i)
            cout << setw(3) << current++;
        cout << endl;
    }
}
int main() {
    int month, year;
    cout << "Enter month and year (MM YYYY): ";
    cin >> month >> year;
    if (month < 1 || month > 12 || year < 1) {
        cout << "Invalid input.\n";
        return 1;
    }

    printCalendar(month, year);

    return 0;
}