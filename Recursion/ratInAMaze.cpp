#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &mat, string path, int n, int m, int i, int j, vector<string> &ans) {

    if (i == n-1 and j == m-1) {
        ans.push_back(path);
        return;
    }

    if (i-1 >= 0 and mat[i-1][j]) {
        path.push_back('U');
        mat[i][j] = 0;
        solve(mat, path, n, m, i-1, j, ans);
        path.pop_back();
        mat[i][j] = 1;
    }
    if (i+1 < n and mat[i+1][j]) {
        path.push_back('D');
        mat[i][j] = 0;
        solve(mat, path, n, m, i+1, j, ans);
        path.pop_back();
        mat[i][j] = 1;
    }
    if (j-1 >= 0 and mat[i][j-1]) {
        path.push_back('L');
        mat[i][j] = 0;
        solve(mat, path, n, m, i, j-1, ans);
        path.pop_back();
        mat[i][j] = 1;
    }
    if (j+1 < m and mat[i][j+1]) {
        path.push_back('R');
        mat[i][j] = 0;
        solve(mat, path, n, m, i, j+1, ans);
        path.pop_back();
        mat[i][j] = 1;
    }
    return;
}

vector<string> findPath(vector<vector<int>> &mat, int n, int m)
{
    // Your code goes here
    vector<string> ans;
    if (!mat[0][0]) return ans;
    solve(mat, "", n, m, 0, 0, ans);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int> (m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    for (auto i : findPath(mat, n, m))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
