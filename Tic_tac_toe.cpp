#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char player = 'X';

void showBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0]==player && board[i][1]==player && board[i][2]==player) ||
            (board[0][i]==player && board[1][i]==player && board[2][i]==player))
            return true;
    }
    return (board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
           (board[0][2]==player && board[1][1]==player && board[2][0]==player);
}

int main() {
    int move;
    int turns = 0;
    while (true) {
        showBoard();
        cout << "Player " << player << ", enter (1-9): ";
        cin >> move;
        if (move < 1 || move > 9) continue;

        int r = (move - 1) / 3, c = (move - 1) % 3;
        if (board[r][c] == 'X' || board[r][c] == 'O') continue;
        board[r][c] = player;
        turns++;

        if (checkWin()) {
            showBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (turns == 9) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}