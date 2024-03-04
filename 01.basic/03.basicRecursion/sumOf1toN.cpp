# include <iostream>
using namespace std;

int sum(int n){
    if (n==0) return 0;
    return n + sum(n-1); // here function call itself with different parameter.
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << (sum(n)) << endl;
}