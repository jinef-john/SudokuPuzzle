## Sudoku Solver
This is a simple sudoku solver that uses backtracking algorithm to solve any given puzzle. The program takes a 9x9 sudoku puzzle as input and returns the solved puzzle.

## Example
![Example](Output\output.JPG)

## Technical details
The program uses a simple backtracking algorithm to solve the puzzle. The algorithm starts at the first empty cell, and tries numbers 1-9. If a number is valid, it places it on the board and moves on to the next empty cell. If the number is not valid, it backtracks and tries the next number. The algorithm continues this process until the puzzle is solved.