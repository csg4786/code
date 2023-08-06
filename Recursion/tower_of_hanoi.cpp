#include <bits/stdc++.h>
using namespace std;

int steps = 0;
void tower_of_hanoi(int n, int start, int mid, int end){
    if (n == 1){
        steps++;
        cout << steps << ". Move disk " << n << " from tower " << start << " to tower " << end << "\n"; 
        return;
    }
    tower_of_hanoi(n-1, start, end, mid);
    steps++;
    cout << steps << ". Move disk " << n << " from tower " << start << " to tower " << end << "\n";
    tower_of_hanoi(n-1, mid, start, end);
}

int main()
{

    int n;
    cin >> n;

    tower_of_hanoi(n, 1, 2, 3);
    cout << steps << "\n";

    return 0;
}
