#include <bits/stdc++.h>
using namespace std;

// Check whether q is a substring of T
bool isSubstring(string T, string q)
{
    if (T.find(q) != string::npos)
    {
        return true;
    }
    return false;
}

// Check whether q is a suffix of T
bool isSuffix(string T, string q)
{
    if (T.length() < q.length())
    {
        return false;
    }
    int pos = T.length() - q.length();
    if (T.substr(pos) == q)
    {
        return true;
    }
    return false;
}

// Count how many times q appears in T
int countOccurrences(string T, string q)
{
    int count = 0;
    size_t pos = T.find(q);
    while (pos != string::npos)
    {
        count++;
        pos = T.find(q, pos + 1);
    }
    return count;
}

// Find the longest repeat in T
string longestRepeat(string T)
{
    string longest;
    int n = T.length();
    vector<vector<int>> lcp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        lcp[i][i] = n - i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (T[i] == T[j])
            {
                lcp[i][j] = lcp[i + 1][j - 1] + 2;
                if (lcp[i][j] > longest.length())
                {
                    longest = T.substr(i, lcp[i][j]);
                }
            }
            else
            {
                lcp[i][j] = 0;
            }
        }
    }
    return longest;
}

// Find the longest common substring of T and q
string longestCommonSubstring(string T, string q)
{
    string longest;
    int n = T.length();
    int m = q.length();
    vector<vector<int>> lcs(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }
            else if (T[i - 1] == q[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (lcs[i][j] > longest.length())
                {
                    longest = T.substr(i - lcs[i][j], lcs[i][j]);
                }
            }
            else
            {
                lcs[i][j] = 0;
            }
        }
    }
    return longest;
}

int main()
{
    string T = "mississippi";
    string q = "iss";
    cout << "T: " << T << endl;
    cout << "q: " << q << endl;
    cout << "isSubstring: " << isSubstring(T, q) << endl;
    cout << "isSuffix: " << isSuffix(T, q) << endl;
    cout << "countOccurrences: " << countOccurrences(T, q) << endl;
    cout << "longestRepeat: " << longestRepeat(T) << endl;
    cout << "longestCommonSubstring: " << longestCommonSubstring(T, q) << endl;
    return 0;
}