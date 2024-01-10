#include <iostream>
#include <vector>
#include <fstream>

#define SIZE 9

void displayBoard(int **board) {
    std::cout << std::endl;
    std::cout << "|-----------------|-----------------|-----------------|" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "|";
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                std::cout << " ___ " << "|";
            } else {
                std::cout << "  " << board[i][j] << "  |";
            }
        }
        std::cout << std::endl;
        if (i == SIZE - 1) {
            std::cout << "|-----------------|-----------------|-----------------|" << std::endl;
        } else if ((i + 1) % 3 == 0) {
            std::cout << "|-----------------|-----------------|-----------------|" << std::endl;
        }
    }
}

bool isValidMove(int **board, int row, int col, int num) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return   false;
        }
    }
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int **board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; ++num) {
                    if (isValidMove(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board)) {
                            return true;
                        }

                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

std::string to_string(int data[9][9]) {
    std::string exported(81, '0');
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            exported[i * 9 + j] += data[i][j];
    return exported;
}


int main() {
    int row, col, num;
    int i = 0, j = 0;
    int **sudokuBoard = new int *[SIZE];

    for (i = 0; i < SIZE; ) {
        sudokuBoard[i] = new int[SIZE];
        i++;
    }

    std::cout << "Welcome to Sudoku! Enter your moves (row, column, number)." << std::endl;
    std::cout << "Use 0 to clear a cell." << std::endl;

    std::cout << "First fill sudoku board:" << std::endl;
    
    std::ifstream inputFile("in.txt");

    for (i = 0; i < SIZE;) {
        for (j = 0; j < SIZE;) {
            inputFile >> row >> col >> num;

            if (row < 1 || row > SIZE || col < 1 || col > SIZE || num < 0 || num > SIZE) {
                std::cout << "Invalid move! Please enter valid file." << std::endl;
                return 0;
            }
            --row;
            --col;

            if (num == 0 || isValidMove(sudokuBoard, row, col, num)) {
                sudokuBoard[row][col] = num;
            } else {
                std::cout << "Invalid move! Please try again." << std::endl;
                continue;
            }
            j++;
        }

        i++;
    }
    std::cout << "Initial board:" << std::endl;

    displayBoard(sudokuBoard);

    std::cout << "Solved board:" << std::endl;
    solveSudoku(sudokuBoard);

    displayBoard(sudokuBoard);

    std::ofstream outputFile("out.txt");
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; ++j) {
            outputFile << i + 1 << " " << j + 1 << " " << sudokuBoard[i][j] << "\n";
        }

    for (i = 0; i < SIZE; ++i)
        delete[] sudokuBoard[i];
    delete[] sudokuBoard;
    return 0;
}
