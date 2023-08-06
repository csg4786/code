#include <bits/stdc++.h>
using namespace std;

void permutations(string s, int n, int i, vector<string> &perm){
    if (i == n) {
        perm.push_back(s);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        swap(s[i], s[j]);
        permutations(s, n, i+1, perm);
        swap(s[i], s[j]);
    }
}

void permutations(string s, string op, int n, int i, vector<bool> mark, vector<string> &perm){
    if (i == n) {
        perm.push_back(op);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (!mark[j]) {
            op.push_back(s[j]);
            mark[j] = true;
            permutations(s, op, n, i+1, mark, perm);
            op.pop_back();
            mark[j] = false;
        }
    }
    return;
}

int main()
{
    string s;
    cin >> s;

    vector<bool> mark(s.length(), false);
    vector<string> perm;

    permutations(s, s.length(), 0, perm);

    for (auto i : perm)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
