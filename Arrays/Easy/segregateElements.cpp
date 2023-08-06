#include <bits/stdc++.h>
using namespace std;

void segregateElements(int arr[],int n)
{
    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if (arr[i] < 0) neg.push_back(arr[i]);
        else pos.push_back(arr[i]);
    }
    int ind = 0;
    while(ind < pos.size()){
        arr[ind]=pos[ind];
        ind++;
    }
    while(ind-pos.size() < neg.size()){
        arr[ind] = neg[ind - pos.size()];
        ind++;
    }
}


int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    segregateElements(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}