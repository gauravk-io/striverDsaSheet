#include <bits/stdc++.h>
using namespace std;

void f(int i, int n)
{
    if (i < 1)
        return;
    f(i - 1, n); // here function call itself and 'i' starts from 'n' and after each ittration its value keep decresing by 1 untill 'i' beacme less than 1. 
    cout << i;
}

int main()
{
    int n;
    cout << "Enter the number";
    cin >> n;
    f(n, n);
}