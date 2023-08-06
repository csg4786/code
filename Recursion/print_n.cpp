#include <bits/stdc++.h>
using namespace std;

void print_n_down(int n){
    if (n == 1){
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    print_n_down(n-1);
}

void print_n_up(int n){
    if (n == 1){
        cout << 1 << " ";
        return;
    }
    print_n_up(n-1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    
    print_n_up(n);
    cout << endl;
    print_n_down(n);

    return 0;
}
