#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int s, int e)
{
    int pivot = v[e], pi = s;
    for (int i = s; i < e; i++)
    {
        if (v[i] < pivot)
        {
            swap(v[i], v[pi]);
            pi++;
        }
    }
    swap(v[pi], v[e]);
    return pi;
}

void quick_sort(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(v, s, e);
    quick_sort(v, s, p - 1);
    quick_sort(v, p + 1, e);
}

int partition(vector<pair<int, int>> &v, int s, int e)
{
    pair <int,int> pivot = v[e];
    int pi = s;
    for (int i = s; i < e; i++)
    {
        if (v[i].second < pivot.second)
        {
            swap(v[i], v[pi]);
            pi++;
        }
    }
    swap(v[pi], v[e]);
    return pi;
}

void quick_sort(vector<pair<int, int>> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(v, s, e);
    quick_sort(v, s, p - 1);
    quick_sort(v, p + 1, e);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<pair<int, int>> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v2[i].first = i;
        v2[i].second = v[i];
    }

    // quick_sort(v, 0, n-1);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    quick_sort(v2, 0, n - 1);
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
