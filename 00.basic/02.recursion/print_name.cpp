#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void f(int i, int n)
{
    if (i > n)
        return;
    cout << "Gaurav\n";  
    f(i+1, n);
}
int main()
{
    int n;
    cout << "Enter the number"; 
    cin >> n;
    f(1, n);
}