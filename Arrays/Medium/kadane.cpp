#include <bits/stdc++.h>
using namespace std;

long long kadane(vector<int> arr, int n){

    long long cs = 0, ms = INT_MIN;

    for (int i = 0; i < n; i++){
        if (cs < 0){
            cs = arr[i];
        } else {
            cs += arr[i];
        }
        ms = max(cs, ms);
    }

    return ms;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string s1 = "ehflcjmgljhbjecdikajfdmadcfdiahkaglkeifdcljcgmfgfmmlijgihiejmfgekaljkmfkdfikjgkb";
    string s2 = "ehflcjmgljhbjecdikajfdmadcfdiahkaglkeifdcljcgmfgflijgihiejmfgekaljkmfkdfikjgkb";

    cout << kadane(arr, n) << endl;

    return 0;
}