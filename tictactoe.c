#include <stdio.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int currentPlayer = 1;  // 1 for player 1, 2 for player 2
char mark;  // X or O for the players

void drawBoard() {
    printf("\n\n\tTic-Tac-Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n\n");
}

int checkWin() {
    // Check rows
    if (board[0] == board[1] && board[1] == board[2]) return 1;
    if (board[3] == board[4] && board[4] == board[5]) return 1;
    if (board[6] == board[7] && board[7] == board[8]) return 1;
    
    // Check columns
    if (board[0] == board[3] && board[3] == board[6]) return 1;
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    
    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8]) return 1;
    if (board[2] == board[4] && board[4] == board[6]) return 1;
    
    // Check for a draw
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return -1;  // Still empty spaces
    }
    
    return 0;  // Draw
}

void makeMove() {
    int choice;
    printf("Player %d, enter a number:  ", currentPlayer);
    scanf("%d", &choice);

    // Adjust for 0-indexing
    choice--;

    if (choice >= 0 && choice < 9 && board[choice] != 'X' && board[choice] != 'O') {
        board[choice] = mark;
    } else {
        printf("Invalid move, try again.\n");
        makeMove();  // Recursive call for invalid move
    }
}

int main() {
    int gameStatus = -1;  // -1 means game is still running
    currentPlayer = 1;
    
    do {
        drawBoard();
        mark = (currentPlayer == 1) ? 'X' : 'O';  // Player 1 is 'X', Player 2 is 'O'
        
        makeMove();
        gameStatus = checkWin();
        
        if (gameStatus == 1) {
            drawBoard();
            printf("==> Player %d wins!\n", currentPlayer);
            break;
        } else if (gameStatus == 0) {
            drawBoard();
            printf("==> It's a draw!\n");
            break;
        }
        
        currentPlayer = (currentPlayer % 2) + 1;  // Switch player
    } while (gameStatus == -1);
    
    return 0;
}
