#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<int,int> a, pair<int,int> b){
    if (a.second == b.second){
        return a.first > b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main()
{
    // vector<int> v;

    // v.push_back(1);
    // v.push_back(20);
    // v.push_back(46);
    // v.push_back(15);
    // v.push_back(7);
    // v.push_back(36);
    // v.push_back(28);
    // v.push_back(25);

    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // sort(v.begin(),v.end());
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // sort(v.begin(),v.end(), greater<int>());
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector < pair<int,int>> vp, vp1;
    vp1.push_back({1,2});
    vp1.push_back({2,1});
    vp1.push_back({4,1});

    for (int i = 0; i < 5; i++)
    {
        vp.push_back({i*i,i});
        vp.push_back({-i*(-i),-i});
    }
    // cout << endl;
    
    sort(vp1.begin(),vp1.end(), mycmp);
    for (auto i : vp1)
    {
        cout << i.first << "," << i.second << " ";
    }
    cout << endl;

    return 0;
}
