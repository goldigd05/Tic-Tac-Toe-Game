#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void resetBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool isWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;

    for (int j = 0; j < 3; j++)
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
            return true;

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int move;
    bool gameEnd = false;
    resetBoard();

    while (!gameEnd) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (isWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameEnd = true;
        } else if (isDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            gameEnd = true;
        } else {
            switchPlayer();
        }
    }
}

int main() {
    char choice;
    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Thanks for playing!\n";
    return 0;
}
