#include <bits/stdc++.h>
using namespace std;

long long sum_of_n(int n){
    if (n == 1){
        return 1;
    }
    return n+sum_of_n(n-1);
}

int main()
{
    int n;
    cin >> n;

    cout << sum_of_n(n);
    
    return 0;
}
