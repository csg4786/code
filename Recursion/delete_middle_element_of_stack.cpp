#include <bits/stdc++.h>
using namespace std;

void delete_mid(stack<int> &s, int n, int i){
    // cout << i << " " << n << "\n";
    if (i == ((n-(!(n%2)))/2)){
        // cout << i << " " << n << "\n";
        s.pop();
        return;
    }
    else {
        // cout << i << " " << n << "\n";
        int temp = s.top();
        s.pop();
        delete_mid(s, n, i+1);
        s.push(temp);
    }
}

void print_stack(stack<int> s){

    if (s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    print_stack(s);
    cout << temp << " ";
}

int main()
{
    int n;
    cin >> n;

    stack<int> s;

   for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    // print_stack(s);
    // cout << endl;
    
    delete_mid(s, n, 0);

    print_stack(s);

    return 0;
}
