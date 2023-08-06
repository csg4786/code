#include <bits/stdc++.h>
using namespace std;

void space_permutation(string ip, string op){
    if (ip.length() == 1){
        op.push_back(ip[0]);
        cout << op << "\n";
        return;
    }

    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    string op1 = op, op2 = op;
    op2.push_back(' ');
    space_permutation(ip, op1);
    space_permutation(ip, op2);
    
}

int main()
{

    string s;
    cin >> s;

    space_permutation(s, "");

    return 0;
}
