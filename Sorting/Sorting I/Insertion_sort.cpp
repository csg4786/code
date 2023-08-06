#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<pair<int, int>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        pair<int, int> c = v[i];
        int hole = i - 1;
        while (hole >= 0 and v[hole].second > c.second)
        {
            v[hole + 1] = v[hole];
            hole--;
        }
        v[hole + 1] = c;
    }
}

void recursive_insertion_sort(vector<pair<int, int>> &v, int i)
{
    if (i == v.size())
    {
        return;
    }
    pair<int, int> c = v[i];
    int hole = i - 1;
    while (hole >= 0 and v[hole].second > c.second)
    {
        v[hole + 1] = v[hole];
        hole--;
    }
    v[hole + 1] = c;
    recursive_insertion_sort(v, i + 1);
}

void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int c = v[i], hole = i - 1;
        while (hole >= 0 and v[hole] > c)
        {
            v[hole + 1] = v[hole];
            hole--;
        }
        v[hole + 1] = c;
    }
}

void recursive_insertion_sort(vector<int> &v, int i)
{
    if (i == v.size())
    {
        return;
    }
    int c = v[i], hole = i - 1;
    while (hole >= 0 and v[hole] > c)
    {
        v[hole + 1] = v[hole];
        hole--;
    }
    v[hole + 1] = c;
    recursive_insertion_sort(v, i + 1);
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

    // insertion_sort(v);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // recursive_insertion_sort(v,0);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;    

    // insertion_sort(v2);
    // for (auto i : v2)
    // {
    //     cout << i.first << " ";
    // }
    // cout << endl;
    // for (auto i : v2)
    // {
    //     cout << i.second << " ";
    // }
    // cout << endl;

    recursive_insertion_sort(v2,0);
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
