#include <bits/stdc++.h>
using namespace std;

bool isValid(char s) {
    return ((s >= '0' and s <= '9') or (s >= 'A' and s <= 'Z') or (s >= 'a' and s <= 'z'));
}

bool checkPalindrome(string st)
{
    // Write your code here.
    int s = 0, e = st.length()-1;
    while (s < e) {
        if (isValid(st[s]) and isValid(st[e])) {
            if ((st[s] == st[e]) or (st[s] == st[e]-'a'+'A') or (st[s]-'a'+'A' == st[e])) {
                s++, e--;
            } else {
                return false;
            }
        } else if (isValid(st[s])) {
            e--;
        } else if (isValid(st[e])) {
            s++;
        } else {
            s++, e--;
        }
    }

    return true;
}

int main()
{
    string s;
    getline(cin, s);

    cout << checkPalindrome(s) << endl;
    return 0;
}