#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter a word or number: ";
    cin >> str;

    string rev = str;
    reverse(rev.begin(), rev.end());

    if (str == rev)
        cout << "It's a palindrome!\n";
    else
        cout << "Not a palindrome.\n";

    return 0;
}