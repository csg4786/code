#include <bits/stdc++.h>
using namespace std;

int dpmemo[1001][1001];

int lcs (string s1, string s2, int i, int j) {
    if (i == 0 or j == 0) {
        return 0;
    }
    if (s1[i-1] == s2[j-1]) {
        return 1 + lcs(s1, s2, i-1, j-1);
    } else {
        return max(lcs(s1, s2, i, j-1), lcs(s1, s2, i-1, j));
    }
}

int lcs_memo (string s1, string s2, int i, int j) {
    if (i == 0 or j == 0)
        return 0;
    if (dpmemo[i][j] != -1)
        return dpmemo[i][j];

    if (s1[i] == s2[j]) {
        return dpmemo[i][j] = 1 + lcs_memo(s1, s2, i-1, j-1);
    } else {
        return dpmemo[i][j] = max(lcs_memo(s1, s2, i, j-1), lcs_memo(s1, s2, i-1, j));
    }
}

int lcs_tab(string s1, string s2) {
    int n = s1.length(), m = s2.length();
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
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return dp[n][m];
}

string lcs_print(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    int dp[n+1][m+1];

    string ans = "";

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
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int a = s1.length(), b = s2.length();

    while (a != 0 and b != 0)
    {
        if (dp[a-1][b] == dp[a][b-1] and s1[a-1] == s2[b-1]) {
            ans = s1[a-1] + ans;
            a--, b--;
        } else if (dp[a-1][b] <= dp[a][b-1]) {
            b--;
        } else {
            a--;
        }
    }
    
    return ans;
}

int fun(vector<int> nums1, vector<int> nums2) {
    int n = nums1.size(), m = nums2.size();

    vector<int> dp1(m+1, 0);
    vector<int> dp2(m+1, 0);
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (nums1[i-1] == nums2[j-1]){
                dp2[j] = dp1[j-1]+1;
            } else {
                dp2[j] = max(dp1[j], dp2[j-1]);
            }
        }
        dp1 = dp2;
    }

    return dp2[m];
}

int main()
{
    // memset(dpmemo, -1, sizeof(dpmemo));

    // string s1, s2;
    // cin >> s1 >> s2;

    // cout << lcs(s1, s2, s1.length(), s2.length()) << "\n";
    // cout << lcs_memo(s1, s2, s1.length(), s2.length()) << "\n";
    // cout << lcs_tab(s1, s2) << "\n";
    // cout << lcs_print(s1, s2) << "\n";

    int n, m;
    cin >> n >> m;

    vector<int> n1(n), n2(m); 

    for (int i = 0; i < n; i++)
    {
        cin >> n1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> n2[i];
    }
    
    cout << fun(n1, n2) << endl;

    return 0;
}
