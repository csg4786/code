#include <bits/stdc++.h>
using namespace std;

void sbsq_sum_k(vector<int> v, vector<int> vo, int k, vector<vector<int>> &vv){
    if (v.size() == 0 and k != 0){
        return;
    }
    if (k == 0){
        vv.push_back(vo);
        return;
    }

    int a = v[0];
    v.erase(v.begin()+0);
    if (k >= a){
        vo.push_back(a);
        sbsq_sum_k(v, vo, k-a, vv);
        vo.pop_back();
        sbsq_sum_k(v, vo, k, vv);
    }
    else{
        sbsq_sum_k(v, vo, k, vv);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n), vo;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<vector<int>> vv;

    sbsq_sum_k(v, vo, k, vv);

    for (auto &it : vv)
    {
        cout << "{ " ;
        for (auto &it2 : it)
        {
            cout << it2 << " ";
        }
        cout << "}\n" ;
    }
    
    return 0;
}
