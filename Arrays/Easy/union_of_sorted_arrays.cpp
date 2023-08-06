#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    if (arr1[i] < arr2[j])
    {
        ans.push_back(arr1[i]);
        i++;
    }
    else if (arr1[i] > arr2[j])
    {
        ans.push_back(arr2[j]);
        j++;
    }
    else
    {
        ans.push_back(arr1[i]);
        i++, j++;
    }
    while (i < n and j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            if (ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++, j++;
        }
    }
    while (i < n)
    {
        if (ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> n >> m;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> v = findUnion(arr1, arr2, n, m);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
