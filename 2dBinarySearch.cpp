#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int s = 0, e = n*m-1;

    int mid = s + (e - s) / 2, i = mid/m, j = mid%m;

    while (s <= e) {
        mid = s+(e-s)/2;
        i = mid/m, j = mid%m;

        cout << mid <<" " << i << " " << j << " " << mat[i][j] << endl;

        if (mat[i][j] == target) {
            return true;
        } else if (mat[i][j] < target) {
            s = mid+1;
        } else {
            e = mid-1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    cout << searchMatrix(mat, 8) << endl;

    return 0;
}