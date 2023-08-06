#include <bits/stdc++.h>
using namespace std;

double sqt(int n, int prec){
    long long val = n*((long long)(pow(10, 2*prec)));

    long long s = 0, e = val/2;

    long long mid, ans;
    while (s <= e) {
      mid = s + (e - s) / 2;

        if (mid <= val/mid){
            ans = mid;
            s = mid+1;
        } else {
            e = mid-1;
        }
    }

    return (1.0*ans/((int)(pow(10, prec))));
}

int main()
{
    int n, prec;
    cin >> n >> prec;

    cout << sqt(n, prec) << endl;

    return 0;
}
