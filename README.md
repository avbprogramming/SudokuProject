# SudokuProject

Introduction
This C++ program is a Sudoku solver that reads an initial Sudoku board from a file (in.txt), solves it, and writes the solution to another file (out.txt). The Sudoku board is represented as a 9x9 grid, and the program uses a backtracking algorithm to find the solution.

Code Overview
The program consists of the following components:

Display Functions:
displayBoard(int **board): Displays the Sudoku board on the console.

Sudoku Solver Functions:
isValidMove(int **board, int row, int col, int num): Checks if placing a number num at position (row, col) is a valid move.
solveSudoku(int **board): Uses backtracking to solve the Sudoku puzzle.

Utility Functions:
to_string(int data[9][9]): Converts a 2D array representing the Sudoku board to a string format.

Main Function (main()):
Initializes the Sudoku board from the input file (in.txt).
Displays the initial board.
Solves the Sudoku puzzle.
Displays the solved board.
Writes the solution to an output file (out.txt).


Usage

Input Format:
The program expects the initial Sudoku board in the in.txt file.
Each line in the file should contain three integers: row, column, and the number to be placed in the corresponding cell.

Output Format:
The program outputs the solved Sudoku board to the console.
The final solution is also written to the out.txt file, with each line containing row, column, and the number in the solved puzzle.

Running the Program:
Compile the program using a C++ compiler: g++ sudoku_solver.cpp -o sudoku_solver.
Run the executable: ./sudoku_solver.

Example
Suppose in.txt contains the following input:
1 1 5
...
9 9 9
The program will solve the Sudoku puzzle and display the initial and solved boards. The solution will also be written to out.txt.

Notes
The program uses a simple backtracking algorithm to solve the Sudoku puzzle.
The input file (in.txt) must adhere to the specified format for successful execution.

Conclusion
This Sudoku solver provides a simple and efficient way to solve Sudoku puzzles using a backtracking approach. Users can input their puzzles through the in.txt file and obtain the solution in the out.txt file.
