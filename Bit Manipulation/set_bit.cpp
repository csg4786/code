// #include <bits/stdc++.h>
// using namespace std;

// bool isSet(int n, int i) {
//     int mask = (1 << (i-1));
//     return n&mask;
// }

// int toggle(int n, int i) {
//     int mask = (1 << (i-1));
//     return n^mask;
// }

// bool isPowerOfTwo(int n) {
//     return (!(n&(n-1)));
// }

// void swp(int &n, int &m) {
//     n = n^m;
//     m = n^m;
//     n = n^m;
// }

// int main()
// {
//     // int n, i;
//     // cin >> n >> i;

//     // isSet(n, i) ? cout <<  "Yes" << endl : cout << "No" << endl;

//     // cout << "Toggled : " << toggle(n, i) << endl;

//     // cout << (isPowerOfTwo(n) ? "" : "Not ") << "Power of 2" << endl;

//     int n, m;
//     cin >> n >> m;

//     cout << n << " " << m << endl;
//     swap(n, m);
//     cout << n << " " << m << endl;

//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

int countValidPermutations(int n)
{
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    function<int(int, int)> isValid = [&](int i, int mask)
    {
        if (mask == (1 << n) - 1)
            return 1;

        if (dp[i][mask] != -1)
            return dp[i][mask];

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if ((i + 1) % (j + 1) == 0 || (j + 1) % (i + 1) == 0)
            {
                if ((mask & (1 << j)) == 0)
                {
                    count += isValid(i + 1, mask | (1 << j));
                }
            }
        }

        dp[i][mask] = count;
        return count;
    };

    return isValid(0, 0);
}

int main()
{
    int n = 4;
    int result = countValidPermutations(n);
    cout << "Number of valid permutations for n = " << n << " is " << result << endl;

    return 0;
}
