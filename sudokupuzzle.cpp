#include <vector>
#include <algorithm> // for random_shuffle incase we need it
#include <iostream>

using namespace std;

// First thing is to print the board. The sudoku puzzle is a 9x9 grid.
void printBoard(vector<vector<int>> board) {
    cout << "*************************" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "*************************" << endl;
}

// Next, we need to check if the number we are trying to place is valid.
// We need to check the row, column, and the 3x3 grid.
bool isValid(vector<vector<int>> board, int row, int col, int num) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // Check the 3x3 grid
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    //for every row in the 3x3 grid, check every column
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Now we need to solve the puzzle. We will use recursion to solve the puzzle.
bool solveSudoku(vector<vector<int>> &board) {
    // First, we need to find an empty cell.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                // Now we need to try numbers 1-9
                for (int num = 1; num <= 9; num++) {
                    // Check if the number is valid
                    if (isValid(board, i, j, num)) {
                        // If the number is valid, place it on the board
                        board[i][j] = num;
                        // Now we need to recursively call the function
                        if (solveSudoku(board)) {
                            return true;
                        }
                        // If the number is not valid, we need to backtrack
                        else {
                            board[i][j] = 0;
                        }
                    }
                }
                // If we tried all numbers 1-9 and none of them worked, we need to backtrack
                return false;
            }
        }
    }
    // If we get here, the puzzle is solved
    return true;
}

int main() {
    // Create the board
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
    };
    cout << "Unsolved Puzzle" << endl;
    // Print the board
    printBoard(board);
    // Solve the puzzle
    solveSudoku(board);
    cout << "Solved Puzzle" << endl;
    // Print the solved puzzle
    printBoard(board);
    return 0;
}
