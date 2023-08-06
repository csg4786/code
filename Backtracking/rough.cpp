#include <bits/stdc++.h>
using namespace std;

void fun (int n){
    if (n <= 3)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < n - 3; i++)
        {
            for (size_t j = 0; j < n - 3 - i; j++)
            {
                cout << " ";
            }
            cout << "*\n";
        }
        for (int i = 0; i < n; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n+1; i++)
    {
        fun(i);
    }
    

    return 0;
}

/*

eyJhbGciOiJQUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6IjIxYmNzMDY0QGlpaXRkbWouYWMuaW4iLCJtaXhwYW5lbElkIjoiMTg2ZjBmNzU4OTExNy0wZGViMzRkZmY0YjI0NS0yNjAzMTg1MS0xNDQwMDAtMTg2ZjBmNzU4OTIzYWQiLCJtaXhwYW5lbFByb2plY3RJZCI6IjRiZmIyNDE0YWI5NzNjNzQxYjZmMDY3YmYwNmQ1NTc1Iiwib3JnIjoiSUlJVERNSiIsInB1YiI6Im5lbzRqLmNvbSIsInJlZyI6IkNoYW5kcmFzaGVraGFyIEdvdWRhIiwic3ViIjoibmVvNGotZGVza3RvcCIsImV4cCI6MTcxMDcwMjUxMCwidmVyIjoiKiIsImlzcyI6Im5lbzRqLmNvbSIsIm5iZiI6MTY3OTA4MDExMCwiaWF0IjoxNjc5MDgwMTEwLCJqdGkiOiJfNFhFSFZiSE0ifQ.l2gfpMzMCl4vhCdFCw_Jdnpq8UUM8R2JkCxt8sB4JVCw522HeRdzDJNBvIcRh-rlQm-GoB0CJI4iHnFzBGMuncmFnnaKkvkJBOTjinWp_Rh1fRlGjCzb-S1_4tMZ5HwTa7kFLkQoegGGW7NOKHdOZLbOdcktEWxmhD0EsiIoh8Dafm6Vi4krl-0Mlix0cdT55Tj6whn4LH8P7NHaqPxCXc4T3Eb17y3c6QprUk8ALWpnZqzwZ_lEoFba5agFxRmdmMS5DxUN8qqfd605N8YDGNKrXO1i1LvFmSelh9ZnqQaneEPueDXdX19Hh26ObrWtK5TlKJTMLdeDq6XlkLCQaQ

*/