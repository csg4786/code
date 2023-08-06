#include <bits/stdc++.h>
#define N 50
using namespace std;

void printQueens(int n, int board[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (board[i][j])
                cout << "Q ";
            else
                cout << "* ";
        printf("\n");
    }
}

bool isSafe(int n, int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool nqueens(int n, int board[N][N], int col)
{

    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isSafe(n, board, i, col))
        {
            board[i][col] = 1;

            if (nqueens(n, board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (nqueens(n, board, 0) == false)
        cout << "Solution does not exist\n";
    else
        printQueens(n, board);

    return 0;
}
