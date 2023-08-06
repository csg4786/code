#include <bits/stdc++.h>
using namespace std;

int lcsubstr_tab(string s1, string s2) {
    int n = s1.length(), m = s2.length(), ans = 0;
    int dp[n+1][m+1];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                if (ans < dp[i][j]) ans = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcsubstr_tab(s1, s2) << "\n";

    return 0;
}
