#include <bits/stdc++.h>
using namespace std;

// void flood_fill(int n, int m, int maze[n][m], int rpos, int cpos, string path){
//     if (rpos >= 0 and rpos < n and cpos >= 0 and cpos < m){
//         if (rpos < n-1 and maze[rpos][cpos] != 1){

//         }
//     }
// }

int main()
{
    // int n = 6, m = 7;
    // // cin >> n >> m;

    // int maze[n][m] = {
    //     {0,1,0,0,0,0,0},
    //     {0,1,0,1,1,1,0},
    //     {0,0,0,0,0,0,0},
    //     {1,0,1,1,0,1,1},
    //     {1,0,1,1,0,1,1},
    //     {1,0,0,0,0,0,0},
    // };

    int n;
    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout <<  a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout <<  b[i] << " ";
    }
    cout << endl;
    

    return 0;
}