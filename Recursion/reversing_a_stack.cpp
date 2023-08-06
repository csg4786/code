#include <bits/stdc++.h>
using namespace std;

void insrt(stack<int> &s, int key){
    if (s.empty()){
        s.push(key);
        return;
    }
    else{
        int temp = s.top();
        s.pop();
        insrt(s, key);
        s.push(temp);
    }
}

void reverse_stack(stack<int> &s){
    if (s.empty()){
        return;
    }
    else{
        int temp = s.top();
        s.pop();
        reverse_stack(s);
        insrt(s, temp);
    }
}

void print_stack(stack<int> s){

    if (s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    print_stack(s);
    cout << temp << " ";
}


int main()
{
    int n;
    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    
    reverse_stack(s);

    print_stack(s);

    return 0;
}

// class Solution
// {
//     public:
//     int p = 1e+7;
//     long long exp(int n, int base, vector<long> &temp)
//     {
//         long long ans = 1;
//         if (n == 0)
//             return 1;
//         if (n == 1)
//             return base;
//         if (temp[n] != -1)
//             return temp[n];
//         int x = n / 2;
//         return temp[n] = ((exp(x, base, temp) % p) * (exp(n - x, base, temp) % p)) % p;
//     }

//     vector<int> search(string pat, string txt)
//     {
//         vector<long> temp(txt.size(), -1);
//         vector<long> temp1(txt.size(), -1);
//         vector<int> ans;

//         int n = pat.size() - 1;
//         long long cmp = 0, xfac = 0, i = n;

//         for (auto it : pat)
//         {
//             cmp = (cmp + (exp(i, 2, temp) * (it - 'a')) % p) % p;
//             xfac = (xfac + (exp(i--, 3, temp1) * (it - 'a' + 1)) % p) % p;
//             //   cout<<cmp<<" ";
//         }

//         //   cout<<'t'-'a';
//         //   cout<<cmp<<" ";
//         int pw = n;
//         long long cmp2 = 0, xfac2 = 0, j = 0;
//         i = 0;
//         for (int i = 0; i < txt.size(); i++)
//         {

//             //   if(i==pat.size()-1 && cmp==cmp2)
//             //   ans.push_back(j+1);

//             if (i < pat.size())
//             {
//                 cmp2 = (cmp2 + (exp(pw, 2, temp) * (txt[i] - 'a')) % p) % p;
//                 xfac2 = (xfac2 + (exp(pw, 3, temp1) * (txt[i] - 'a' + 1)) % p) % p;
//                 pw--;
//             }

//             else
//             {
//                 cmp2 = (cmp2 - (exp(n, 2, temp) * (txt[j] - 'a')) % p) % p;

//                 cmp2 = (cmp2 * 2) % p;
//                 cmp2 = (cmp2 + (exp(0, 2, temp) * (txt[i] - 'a')) % p) % p;

//                 xfac2 = (xfac2 - (exp(n, 3, temp1) * (txt[j++] - 'a' + 1)) % p) % p;

//                 xfac2 = (xfac2 * 3) % p;
//                 xfac2 = (xfac2 + (exp(0, 3, temp1) * (txt[i] - 'a' + 1)) % p) % p;
//                 //   cout<<cmp2<<" ";
//                 //   cout<<(exp(0,2)*(txt[i]-'a'))%p<<" ";
//             }

//             if (i >= pat.size() - 1 && cmp == cmp2 && xfac2 == xfac)
//                 ans.push_back(j + 1);
//             //   cout<<cmp<<" "<<cmp2<<"\n";
//         }
//         return ans;
//     }
// };
