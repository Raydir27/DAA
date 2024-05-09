#include <iostream>

using namespace std;

#define N 4

bool isSafe(int board[N][N], int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;
    
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;
    
    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1))
                return true;
            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

bool solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    cout << "Solution exists. The board is:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main() {
    solveNQueens();
    return 0;
}