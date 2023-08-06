#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &v, int s, int e){
    if (s > e){
        return;
    }
    swap(v[s],v[e]);
    rev(v,s+1,e-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    rev(v,0,n-1);

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    
    
    return 0;
}
