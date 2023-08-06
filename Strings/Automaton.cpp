#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void compute_automaton(string s, vector<vector<int>> &aut)
{
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i - 1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (aut[i][c] == 0)
                aut[i][c] = 0;
            else
                aut[i][c] = 1;
        }
    }
}

vector<int> fsm(string txt, string pat)
{
    int M = pat.length();
    int N = txt.length();

    vector<int> pi = prefix_function(pat), occurences;
 
    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            occurences.push_back(i-j);
            j = pi[j - 1];
        }
 
        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = pi[j - 1];
            else
                i = i + 1;
        }
    }

    return occurences;
}


int main()
{
    string text, pattern;

    cin >> text;
    cin >> pattern;

    vector<vector<int>> aut;
    compute_automaton(pattern, aut);

    cout << "Computed Automaton : \n";
    for (auto i : aut)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    vector<int> occurences = fsm(text, pattern);

    for (auto i : occurences)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
