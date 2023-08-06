#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

    while (s[0] == ' ') {
        s.erase(s.begin());
    }

    while (s[s.length()-1] == ' ') {
        s.pop_back();
    }
    
    int n = s.length();
    int j = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << s[i] << " " << j << " ";
        // cout << endl << s << endl;
        if (s[i] == ' ') {
            if (i > 0 and s[i] == ' ' and s[i-1] == ' ') {
                s.erase(s.begin()+i);
                i--;
            } else {
                reverse(s.begin()+j, s.begin()+i);
                j = i+1;
            }
        }
    } cout << endl;

    reverse(s.begin() + j, s.end());
    reverse(s.begin(), s.end());

    return s;
}

int main()
{
    string s;
    getline(cin, s);

    cout << s << endl;
    // for (int i = 0; i < s.length(); i++) {
    //     cout << i;
    // }
    cout << endl;
    cout << reverseWords(s) << endl;

    return 0;
}