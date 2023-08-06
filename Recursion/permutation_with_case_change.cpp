#include <bits/stdc++.h>
using namespace std;


// assumption : only lowercase english letters are allowed
void case_permutation(string ip, string op){
    if (ip == ""){
        cout << op << "\n";
        return;
    }

    string op1 = op, op2 = op;
    op1.push_back(ip[0]);
    op2.push_back((char)(ip[0]-32));
    ip.erase(ip.begin());
    case_permutation(ip, op1);
    case_permutation(ip, op2);
}

// assumption : only lowercase english letters are allowed

void letter_case_permutation(string ip, string op){
    if(ip == ""){
        cout << op << "\n";
        return;
    }

    if (ip[0] >= 65 and ip[0] <= 90){
        string op1 = op, op2 = op;
        op1.push_back(ip[0]);
        op2.push_back((char)(ip[0]+32));
        ip.erase(ip.begin());
        letter_case_permutation(ip, op1);
        letter_case_permutation(ip, op2);
        return;
    }
    else if (ip[0] >= 97 and ip[0] <= 122){
        string op1 = op, op2 = op;
        op1.push_back(ip[0]);
        op2.push_back((char)(ip[0]-32));
        ip.erase(ip.begin());
        letter_case_permutation(ip, op1);
        letter_case_permutation(ip, op2);
        return;
    }
    op.push_back(ip[0]);
    ip.erase(ip.begin());
    letter_case_permutation(ip, op);
}

int main()
{
    string s;
    cin >> s;

    letter_case_permutation(s,"");

    return 0;
}
