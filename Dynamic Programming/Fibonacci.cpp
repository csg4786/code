#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

long long int fib(int n)
{
    if (n < 2){
        return n;
    }
    return (mp[n]) ? mp[n] : mp[n] = fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << "\n" ;

    return 0;
}
