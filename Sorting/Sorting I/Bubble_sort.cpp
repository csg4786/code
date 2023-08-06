#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<pair<int, int>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j].second > v[j + 1].second)
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
void recursive_bubble_sort(vector<pair<int, int>> &v, int i)
{
    if (i == v.size())
    {
        return;
    }
    for (int j = 0; j < v.size() - i - 1; j++)
    {
        if (v[j].second > v[j + 1].second)
        {
            swap(v[j], v[j + 1]);
        }
    }
    recursive_bubble_sort(v,i+1);
}

void bubble_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void recursive_bubble_sort(vector<int> &v, int i)
{
    if (i == v.size())
    {
        return;
    }
    for (int j = 0; j < v.size() - i - 1; j++)
    {
        if (v[j] > v[j + 1])
        {
            swap(v[j], v[j + 1]);
        }
    }
    recursive_bubble_sort(v,i+1);
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

    // bubble_sort(v);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // recursive_bubble_sort(v,0);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // bubble_sort(v2);
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

    recursive_bubble_sort(v2,0);
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
