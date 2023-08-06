#include <bits/stdc++.h>
using namespace std;

void binary_string(int n, string op, vector<string> &ans){
    if (n == 0){
        ans.push_back(op);
        return;
    }

    string op1=op, op2=op;
    op1.push_back('0');
    op2.push_back('1');
    binary_string(n-1, op1, ans);
    binary_string(n-1, op2, ans);
}

void more_ones_binary_string(int n, string op, vector<string> &ans){
    if (n == 0){
        int count = 0;
        for (int i = 0; i < op.length(); i++){
            if (op[i] == '1'){
                count++;
            }
        }
        if (count >= ceil(op.length()/2.0)){
            ans.push_back(op);
        }
        return;
    }

    string op1=op, op2=op;
    op1.push_back('0');
    op2.push_back('1');
    more_ones_binary_string(n-1, op1, ans);
    more_ones_binary_string(n-1, op2, ans);
}

void more_prefix_ones_binary_string(int n, int oc, int zc, string op, vector<string> &ans){
    if (n == 0){
        ans.push_back(op);
        return;
    }

    if (oc > zc){
        string op1=op, op2=op;
        op1.push_back('0');
        op2.push_back('1');
        more_prefix_ones_binary_string(n - 1, oc, zc+1, op1, ans);
        more_prefix_ones_binary_string(n - 1, oc+1, zc, op2, ans);
    }
    else{
        op.push_back('1');
        more_prefix_ones_binary_string(n - 1, oc+1, zc, op, ans);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans;

    more_prefix_ones_binary_string(n, 0, 0, "", ans);

    for (auto &it : ans)
    {
        cout << it << "\n";
    }

    return 0;
}
