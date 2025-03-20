#include <iostream>
#include <vector>

using namespace std;

vector<char> board(9, ' ');
bool turnO = true; // Player O starts
int count = 0;

vector<vector<int>> winPatterns = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << "  ";
        if ((i + 1) % 3 != 0) {
            cout << "|";
        } else if (i < 8) {
            cout << "\n--------------\n";
        }
    }
    cout << "\n\n";
}

bool checkWinner() {
    for (auto pattern : winPatterns) {
        char pos1 = board[pattern[0]];
        char pos2 = board[pattern[1]];
        char pos3 = board[pattern[2]];

        if (pos1 != ' ' && pos1 == pos2 && pos2 == pos3) {
            cout << "Congratulations! Winner is " << pos1 << "\n";
            return true;
        }
    }
    return false;
}

void gameDraw() {
    cout << "Game was a draw! Play Again." << endl;
}

void resetGame() {
    board.assign(9, ' ');
    turnO = true;
    count = 0;
}

int main() {
    int move;
    bool gameOver = false;
    
    while (!gameOver) {
        displayBoard();
        cout << "Player " << (turnO ? "O" : "X") << "'s turn. Enter position (0-8): ";
        cin >> move;
        
        if (move < 0 || move >= 9 || board[move] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[move] = turnO ? 'O' : 'X';
        turnO = !turnO;
        count++;

        if (checkWinner()) {
            displayBoard();
            gameOver = true;
        } else if (count == 9) {
            displayBoard();
            gameDraw();
            gameOver = true;
        }
    }

    cout << "Do you want to play again? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        resetGame();
        main(); // Restart the game
    }
    return 0;
}
