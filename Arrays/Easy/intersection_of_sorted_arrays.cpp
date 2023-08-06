#include <bits/stdc++.h>
using namespace std;

vector<int> findIntersection(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++, j++;
        }
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

    vector<int> v = findIntersection(arr1, arr2, n, m);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
