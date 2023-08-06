
#include <bits/stdc++.h>
using namespace std;

// int josephus(vector<int> v, int k, int pos){
//     if (v.size() == 1){
//         return v[0];
//     }
    
//     int i = (pos+(k-1))%(v.size());
//     v.erase(v.begin()+i);
    
//     return josephus(v, k, (i)%v.size());
// }

int josephus(int n, int k){
    if (n == 1){
        return 0;
    }

    return (josephus(n-1, k)+k)%n;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i+1;
    }
    
    // cout << josephus(v, k, 0);
    cout << josephus(n, k) + 1;

    return 0;
}

