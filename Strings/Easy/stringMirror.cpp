#include <bits/stdc++.h>
using namespace std;

string stringMirror(string str)
{
    string sample1 = "", sample2 = "";
    sample1.push_back(str[0]);
    sample1.push_back(str[0]);
    sample2.push_back(str[0]);
    sample2.push_back(str[0]);

    // cout << sample1 << " " << sample2 << endl;

    for (int i = 1; i < str.length(); i++)
    {
        string s = "";
        s.push_back(str[i]);
        s.push_back(str[i]);
        sample1.insert(i, s);
        // cout << sample1 << " " << sample2 << " " << s << endl;

        if (sample1 < sample2)
        {
            sample2.insert(i, s);
            // cout << sample1 << " " << sample2 << " " << s << endl;
        }
    }

    // cout << sample1 << " " << sample2 <<endl;
    return sample2;
}

int main()
{
    string s;
    cin >> s;

    cout << stringMirror(s) << endl;

    return 0;
}