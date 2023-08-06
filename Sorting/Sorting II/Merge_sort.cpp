#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int s, int e)
{
    vector<int> temp(e - s + 1);
    int i = s, m = (s + e) / 2, j = m + 1, ind = 0;
    while (i <= m and j <= e)
    {
        if (v[i] <= v[j])
        {
            temp[ind++] = v[i++];
        }
        else
        {
            temp[ind++] = v[j++];
        }
    }
    while (i <= m)
    {
        temp[ind++] = v[i++];
    }
    while (j <= e)
    {
        temp[ind++] = v[j++];
    }
    int k = 0;
    for (int i = s; i < e+1; i++)
    {
        v[i] = temp[k++];
    }
    return;
}

void merge_sort(vector<int> &v, int s, int e){
    int m = (s+e)/2;
    if (s >= e){
        return;
    }
    merge_sort(v,s,m);
    merge_sort(v,m+1,e);
    return merge(v,s,e);
}

void merge(vector<pair<int,int>> &v, int s, int e)
{
    vector<pair<int,int>> temp(e - s + 1);
    int i = s, m = (s + e) / 2, j = m + 1, ind = 0;
    while (i <= m and j <= e)
    {
        if (v[i].second <= v[j].second)
        {
            temp[ind++] = v[i++];
        }
        else
        {
            temp[ind++] = v[j++];
        }
    }
    while (i <= m)
    {
        temp[ind++] = v[i++];
    }
    while (j <= e)
    {
        temp[ind++] = v[j++];
    }
    int k = 0;
    for (int i = s; i < e+1; i++)
    {
        v[i] = temp[k++];
    }
    return;
}

void merge_sort(vector<pair<int,int>> &v, int s, int e){
    int m = (s+e)/2;
    if (s >= e){
        return;
    }
    merge_sort(v,s,m);
    merge_sort(v,m+1,e);
    return merge(v,s,e);
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

    // merge_sort(v, 0, n-1);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    merge_sort(v2, 0, n-1);
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
