#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int count = 1, rev = 0, n = chars.size();
    vector<char> ans;
    for (int i = 1; i < n; i++) {
        if (chars[i] != chars[i-1]) {
            ans.push_back(chars[i-1]);
            if (count > 1) {
                int flag = 0;
                while (count) {
                    if (count%10 == 0) {
                        flag++;
                    }
                    rev = rev*10 + count%10;
                    count /= 10;
                }
                while (rev) {
                    ans.push_back('0'+rev%10);
                    rev /= 10;
                }
                while (flag--) {
                    ans.push_back('0');
                }
            }
            count = 1;
        } else {
            count++;
        }
    }
    ans.push_back(chars[n-1]);
    if (count > 1) {
        int flag = 0;
        while (count) {
            if (count%10 == 0) {
                flag++;
            }
            rev = rev*10 + count%10;
            count /= 10;
        }
        while (rev) {
            ans.push_back('0'+rev%10);
            rev /= 10;
        }
        while (flag--) {
            ans.push_back('0');
        }
    }
    chars = ans;
    return chars.size();
}

int main()
{
    int x;
    cin >> x;
    vector<char> chars(x);
    for (int i = 0; i < x; i++)
    {
        cin >> chars[i];
    }

    for (auto i : chars)
    {
        cout << i << " ";
    }
    cout << endl;

    int y = compress(chars);

    for (auto i : chars)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}