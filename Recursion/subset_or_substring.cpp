#include <bits/stdc++.h>
using namespace std;

// hashFunction
struct hf 
{
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};

void substrings(string ip,string op){

    if (ip.length() == 0){
        cout << op << endl;
        return;
    }

    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    substrings(ip, op1);
    substrings(ip, op2);
}

void unique_substrings(string ip,string op, unordered_set<string> &ans){

    if (ip.length() == 0){
        // cout << op << endl;
        ans.insert(op);
        return;
    }

    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    unique_substrings(ip, op1, ans);
    unique_substrings(ip, op2, ans);
}

void unique_substrings(vector<int> ip, vector<int> op, int n, int i, unordered_set<vector<int>, hf> &ans){

    if (i == n){
        ans.insert(op);
        return;
    }
    unique_substrings(ip, op, n, i+1, ans);
    op.push_back(ip[i]);
    unique_substrings(ip, op, n, i+1, ans);
}

// void unique_substrings(vector<int> ip, vector<int> op, int n, int i, vector<vector<int>> &ans){

//     ans.push_back(op);
//     for(int j = i; j < n; j++){
//         if(!(j != i && ip[j] == ip[j-1])) {
//             op.push_back(ip[j]);
//             unique_substrings(ip, op, n, j+1 ,ans);
//             op.pop_back();
//         }
//     }
//     return;
// }


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> op;
    unordered_set<vector<int>, hf> s;
    vector<vector<int>> ans;
    unique_substrings(arr, op, n, 0, s);
    for (auto v: s) {
        ans.push_back(v);
    }

    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1;

    unordered_set<string> ans;

    // substrings(s1, s2);
    unique_substrings(s1, s2, ans);

    for (auto it : ans)
    {
        cout << it << "\n";
    }
    
    return 0;
}
