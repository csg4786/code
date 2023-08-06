#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector <pair<int,int>> &v){
    int n = v.size();
    for (int i = 0; i < n-1; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (v[j].second < v[k].second){
                k = j;
            }
        }
        swap(v[i],v[k]);
    }
}

void selection_sort(vector <int> &v){
    int n = v.size();
    for (int i = 0; i < n-1; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (v[j] < v[k]){
                k = j;
            }
        }
        swap(v[i],v[k]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<pair<int,int>> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v2[i].first = i;
        v2[i].second = v[i];
    }

    // selection_sort(v);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    selection_sort(v2);
    for (auto i : v2)
    {
        cout << i.first << " ";
    }
    cout << endl;
    for (auto i : v2)
    {
        cout << i.second << " ";
    }
    cout << endl;
    
    return 0;
}
