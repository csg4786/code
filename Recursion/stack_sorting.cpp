#include <bits/stdc++.h>
using namespace std;

void insrt(stack<int> &s, int key){
    if (s.empty() or key >= s.top()){
        s.push(key);
        return;
    }
    else{
        int temp = s.top();
        s.pop();
        insrt(s, key);
        s.push(temp);
    }
}

void sort_stack(stack<int> &s){
    if (s.empty()){
        return;
    }
    else{
        int temp = s.top();
        s.pop();
        sort_stack(s);
        insrt(s, temp);
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
    while (n--)
    {
        int x;
        cin >> x;
        s.push(x);
    }
    
    sort_stack(s);

    print_stack(s);

    return 0;
}