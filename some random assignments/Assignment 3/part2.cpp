// ********************************
// Description: This program is plays tic tac toe 
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 21, 2025
// Status: Complete
// ********************************

#include <iostream>
#include <vector> 

void printBoard(const char board[3][3]);
void getPlayerInput(char currentPlayer, char board[3][3]);
bool checkWin(const char board[3][3], char player);
bool checkTie(const char board[3][3]);




int main() {
    char board[3][3];
    char currentPlayer = 'X'; 
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '*';
        }
    }


    while (true) {
        printBoard(board);

        getPlayerInput(currentPlayer, board);

        if (checkWin(board, currentPlayer)) {
            printBoard(board); // Display final board with winning move
            std::cout << "\nPlayer " << currentPlayer << " wins! Congratulations!" << std::endl;
            break; 
        }

        if (checkTie(board)) {
            printBoard(board); // Display final board for tie
            std::cout << "\nThe game is a tie!" << std::endl;
            break; 
        }

        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    return 0;
}


// displays board
void printBoard(const char board[3][3]) {
    std::cout << "\n   1   2   3" << std::endl; // Column headers
    std::cout << "  -------------" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " |"; // Row header (1-based for user)
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " |";
        }
        std::cout << std::endl;
        std::cout << "  -------------" << std::endl;
    }
}


//prompts player for their mov eand checks if its valid

void getPlayerInput(char currentPlayer, char board[3][3]) {
    int row = -1;
    int col = -1;

    while (true) {
        std::cout << "\nPlayer " << currentPlayer << "'s turn." << std::endl;
        std::cout << "Enter row (1-3): ";
        std::cin >> row;
        std::cout << "Enter column (1-3): ";
        std::cin >> col;

        //checks if input is legal
        if (std::cin.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
            std::cout << "Invalid input. Please enter numbers between 1 and 3 for row and column." << std::endl;
        } else if (board[row - 1][col - 1] != '*') { 
            std::cout << "That spot is already taken! Please select another location." << std::endl;
        } else {
            board[row - 1][col - 1] = currentPlayer;
            break; 
        }
    }
}


// check if play has won, 

bool checkWin(const char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Check row i
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Check column i
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Top-left to bottom-right
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) { // Top-right to bottom-left
        return true;
    }

    return false;
}

// ------------------------------------------------------------------------------------------------------------------

//checks if tie or not
bool checkTie(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}