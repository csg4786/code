#include <bits/stdc++.h>
using namespace std;

void subsequence(string si, string so, vector<string> &vs){
    if (si.length() == 0){
        vs.push_back(so);
        return;
    }

    string so1 = so, so2 = so;
    so2 += si[0];
    si.erase(si.begin()+0);
    
    subsequence(si, so1, vs);
    subsequence(si, so2, vs);
}

int main()
{
    string s;
    cin >> s;

    vector<string> vs;

    subsequence(s, "", vs);

    for (auto &it : vs)
    {
        if (it == "") cout << "{ - }" << "\n";
        else cout << "{ " << it << " }" << "\n";
    }

    return 0;
}
