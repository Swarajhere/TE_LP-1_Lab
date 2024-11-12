#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();
    // check left side row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }
    // check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    // check lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

void printBoard(vector<vector<int>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << j + 1 << " ";
            }
        }
    }
    cout << endl;
}

void solveNQueens(vector<vector<int>> &board, int col)
{
    int n = board.size();
    if (col == n)
    {
        printBoard(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            // recursive call
            solveNQueens(board, col + 1);
            // backtrack -
            board[i][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    cout << "All possible solutions- " << endl;
    solveNQueens(board, 0);

    return 0;
}
