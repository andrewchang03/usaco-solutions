#include <iostream>
using namespace std;

int main () {
    string board[3] = {"---","---","---"};
    int r, c, cond = 1;
    char piece = 'X';
    while (cond) {
        cin >> r >> c;
        if (r >= 0 && r <= 2 && c >= 0 && c <= 2 && board[r][c] == '-') {
            board[r][c] = piece;
            if (piece == 'X') piece = 'O';
            else piece = 'X';
            for (int i = 0; i < 3; i++) {for (int j = 0; j < 3; j++) {cout << board[i][j];} cout << endl;}
            if ((board[r][0] == board[r][1] && board[r][0] == board[r][2]) || (board[0][c] == board[1][c] && board[0][c] == board[2][c]) || (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '-') || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != '-')) {
                cout << "You win" << endl;
                cond = 0;
            }
        } else cout << "Invalid Move" << endl;
    }
}
