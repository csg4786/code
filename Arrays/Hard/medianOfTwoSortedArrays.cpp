#include <bits/stdc++.h>
using namespace std;

double median1(vector<int> &arr1, vector<int> &arr2){

    int n = arr1.size(), m = arr2.size();

    vector<int> all(n+m);

    int i = 0, j = 0;

    int ind = 0;
    while (i < n and j < m)
    {
        if (arr1[i] < arr2[j]){
            all[ind++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j]){
            all[ind++] = arr2[j++];
        }
        else{
            all[ind++] = arr1[i++];
            all[ind++] = arr2[j++];
        }
    }
    
    while (i < n)
    {
        all[ind++] = arr1[i++];
    }
    
    while (j < m)
    {
        all[ind++] = arr2[j++];
    }

    if ((n+m)%2){
        return (1.0*all[(n+m)/2]);
    } else {
        return ((1.0*all[(n+m)/2]+all[(n+m)/2-1])/2);
    }
}

double median2(vector<int> &arr1, vector<int> &arr2){
    
    int n = arr1.size(), m = arr2.size();
    int total = n+m;

    // vector<int> a, b;
    // (m < n) ? a =  arr2, b = arr1 : a = arr1, b = arr2;
    
    // if (m < n){
    //     a.insert(a.begin(), arr2.begin(), arr2.end());
    //     b.insert(b.begin(), arr1.begin(), arr1.end());
    // }
    // else{
    //     b.insert(b.begin(), arr2.begin(), arr2.end());
    //     a.insert(a.begin(), arr1.begin(), arr1.end());
    // }

    if (m >= n){
        int m1 = (arr1.size() / 2) - 1;
        int m2 = total / 2 - m1 - 2;

        while (arr1[m1] > arr2[m2 + 1] or arr2[m2] > arr1[m1 + 1])
        {

            if (arr1[m1] > arr2[m2 + 1])
            {
                m1--;
                m2++;
            }
            else if (arr2[m2] > arr1[m1 + 1])
            {
                m1++, m2--;
            }
        }

        int l1 = (m1 >= 0) ? arr1[m1] : INT_MIN;
        int l2 = (m2 >= 0) ? arr2[m2] : INT_MIN;
        int r1 = (m1 < arr1.size()) ? arr1[m1 + 1] : INT_MAX;
        int r2 = (m2 < arr2.size()) ? arr2[m2 + 1] : INT_MAX;

        if (total % 2)
        {
            return (1.0 * min(r1, r2));
        }
        else
        {
            return (1.0 * max(l1, l2) + min(r1, r2)) / 2;
        }
    } else {
        int m1 = (arr2.size() / 2) - 1;
        int m2 = total / 2 - m1 - 2;

        while (arr2[m1] > arr2[m2 + 1] or arr1[m2] > arr2[m1 + 1])
        {

            if (arr2[m1] > arr1[m2 + 1])
            {
                m1--;
                m2++;
            }
            else if (arr1[m2] > arr2[m1 + 1])
            {
                m1++, m2--;
            }
        }

        int l1 = (m1 >= 0) ? arr2[m1] : INT_MIN;
        int l2 = (m2 >= 0) ? arr1[m2] : INT_MIN;
        int r1 = (m1 < arr2.size()) ? arr2[m1 + 1] : INT_MAX;
        int r2 = (m2 < arr1.size()) ? arr1[m2 + 1] : INT_MAX;

        if (total % 2)
        {
            return (1.0 * min(r1, r2));
        }
        else
        {
            return (1.0 * max(l1, l2) + min(r1, r2)) / 2;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m);

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    
    cout << median1(arr1, arr2) << endl;
    cout << median2(arr1, arr2) << endl;

    return 0;
}