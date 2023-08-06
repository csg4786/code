#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, string> dp;
int c1 = 0, c2 = 0, c3 = 0;
void lcs_memo(string str1, string str2, int i, int j, string &ans) {
    c1++;
    if (i == str1.length() or j == str2.length()) {
        return;
    }
    if (dp.find({i, j}) == dp.end()){
        if (str1[i] == str2[j]) {
            ans.push_back(str1[i]);
            lcs_memo(str1, str2, i+1, j+1, ans);
            // cout << "1. " << ans <<"\n";
        }
        else {
            string choice1 = "", choice2 = "";
            lcs_memo(str1, str2, i+1, j, choice1);
            lcs_memo(str1, str2, i, j+1, choice2);
            (choice1.length() >= choice2.length()) ? ans += choice1 : ans += choice2;
            // cout << "2. " << ans <<"\n";
        }
        dp[{i, j}] = ans;
    }
    else {
        ans = dp[{i, j}];
    }
}

void lcs_tab(string str1, string str2, string &ans) {

    int n = str1.length(), m = str2.length();

    vector<vector<int>> dp2(n+1, vector<int> (m+1, 0));


    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+ 1; j++)
        {
            c2++;
            if (str1[i-1] == str2[j-1]) {
                dp2[i][j] = 1 + dp2[i-1][j-1];
            }
            else {
                dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
            }
        }
    }

    int a = n, b = m;

    while (a != 0 and b != 0)
    {
        if (dp2[a-1][b] == dp2[a][b-1] and str1[a-1] == str2[b-1]) {
            ans = str1[a-1] + ans;
            // cout << ans << " " << str1[a-1] << " " << a << " " << b << "\n";
            a--, b--;
        } else if (dp2[a-1][b] == dp2[a][b-1] and str1[a-1] != str2[b-1]) {
            b--;
        } else if (dp2[a-1][b] > dp2[a][b-1]) {
            a--;
        } else {
            b--;
        }
    }
}

void lcs(string str1, string str2, int i, int j, string &ans) {
    c3++;
    if (i == str1.length() or j == str2.length()) {
        return;
    }

    if (str1[i] == str2[j]) {
        ans.push_back(str1[i]);
        lcs(str1, str2, i+1, j+1, ans);
        // cout << "1. " << ans <<"\n";
    }
    else {
        string choice1 = "", choice2 = "";
        lcs(str1, str2, i+1, j, choice1);
        lcs(str1, str2, i, j+1, choice2);
        (choice1.length() >= choice2.length()) ? ans += choice1 : ans += choice2;
        // cout << "2. " << ans <<"\n";
    }
}

int main()
{
    string str1, str2, s1 = "", s2 = "", s3 = "";
    cin >> str1 >> str2;

    lcs(str1, str2, 0, 0, s1);
    lcs_memo(str1, str2, 0, 0, s2);
    lcs_tab(str1, str2, s3);

    cout << "Brute Force : " << s1 << "\n";
    cout << "Memoization : " << s2 << "\n";
    cout << "Tabulation : " << s3 << "\n";
    cout << c1 << " " << c2 << " " << c3 << "\n";

    return 0;
}
