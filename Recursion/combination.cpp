#include <bits/stdc++.h>
using namespace std;

long long ncr(int n, int r){
    if (n == r || r == 0){
        return 1;
    }
    if (r == 1){
        return n;
    }
    return ncr(n-1,r)+ncr(n-1,r-1);
}

int main()
{
    
    int n,r;
    cin >> n >>r;

    cout << ncr(n,r);

    return 0;
}
