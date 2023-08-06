#include <bits/stdc++.h>
using namespace std;

// count digits
// reverse a number
// gcd and lcm
//

// int count_digits(int n)                 // O(log(n))
// {
//     int c = 0;
//     while (n)
//     {
//         n /= 10;
//         c++;
//     }
//     return c;
// }

// int count_digits(int n)                 // O(1)
// {
//     return log10(n) + 1;
// }

// long long reversedBits(long long X)
// {
//     bool flag = (X >= 0) ? true : false;
//     X = (X >= 0) ? X : -(X + 1);
//     long long n = 0;
//     string s = "";
//     cout << X << endl;
//     while (X)
//     {
//         s = (char)('0' + (X % 2)) + s;
//         cout << s << " " << X << endl;
//         X /= 2;
//     }
//     cout << s << endl;
//     reverse(s.begin(), s.end());
//     cout << s << endl;
//     for (int i = s.length() - 1; i >= 0; i--)
//     {
//         n += ((int)(s[i] - '0')) * pow(2, s.length() - i - 1);
//         cout << s << " " << n << endl;
//     }
//     cout << s << " " << n << endl;
//     n *= pow(2, 32 - s.length());
//     cout << s << " " << n << endl;
//     return n;
// }

// int reverse(int n)
// {
//     long long int N = n, n1 = n;
//     bool flag = true;
//     if (n1 < 0){
//         flag = false;
//         n1 = -n1;
//         N = -N;
//     }
//     long long int k = 0;
//     for (int i = (n1)?log10(n1):1; i >= 0; i--)
//     {
//         k += (N%10)*pow(10,i);
//         if (k > (int)(pow(2,31)-1) || k < (int)(pow(2,32))){
//             return 0;
//         }
//         N /= 10;
//     }
//     k = (flag)? k : -k;
//     return k;
// }

int reverse(int x)

{
    int n = x;
    bool flag = false;
    if (x < 0)
    {
        flag = true;
        n = -x;
    }

    int N = n;
    int k = 0;
    for (int i = (n) ? log10(n) : 1; i >= 0; i--)
    {
        k += (N % 10) * pow(10, i);
        N /= 10;
    }
    int K = k;
    int j = 0;
    for (int i = (K) ? log10(K) : 1; i >= 0; i--)
    {
        j += (k % 10) * pow(10, i);
        k /= 10;
    }
    if (n > 0 and j > 0)
    {
        K = (!flag) ? K : -K;
        return K;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // long long n;
    // cin >> n;

    // cout << reverse(n) << endl;
    // cout << count_digits(n) << endl;

    // long long k = 2147483649;
    // cout << k << " " << (int)k << endl;

    cout << gcd(4,2);

    return 0;
}

// 2147483647
// 2147447412