#include <bits/stdc++.h>
using namespace std;
/*
Take a day number and print the corresponding day .
for 1 print monday ,
for 2 print tuesday and so on.
*/
int main()
{
    int day; // day variable is declared.
    cin >> day; // input is taken.
    switch (day)
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "Invalid";
    }
    return 0;
}
