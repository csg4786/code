#include <bits/stdc++.h>
using namespace std;

void all_balanced_parantheses(int open, int close, string op, vector<string> &ans){
    if (open == 0 and close == 0){
        ans.push_back(op);
        return;
    }

    if (open == 0 and close > 0){
        op.push_back(')');
        all_balanced_parantheses(open, close-1, op, ans);
    }
    else if (open <  close){
        string op1 = op, op2 = op;
        op1.push_back('(');
        op2.push_back(')');
        all_balanced_parantheses(open-1, close, op1, ans);
        all_balanced_parantheses(open, close-1, op2, ans);
    }
    else if (open == close) {
        op.push_back('(');
        all_balanced_parantheses(open-1, close, op, ans);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans;

    all_balanced_parantheses(n, n, "", ans);

    for (auto &it : ans)
    {
        cout << it << "\n";
    }
    

    return 0;
}
