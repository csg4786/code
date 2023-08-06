#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}

bool fun(string s)
{

    int n = s.length();
    for (int i = 0; i < n - 3; i++)
    {
        if (isvowel(s[i]) && isvowel(s[i+1]) && isvowel(s[i+2]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    (fun(s)) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
