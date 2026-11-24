/*
 * Tic-Tac-Toe Game (Two Players) in C
 * Concepts used: 2D arrays, functions, conditional statements, loops
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 3

/* Function prototypes */
void initBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int  getMove(char board[SIZE][SIZE], char player, int playerNo);
int  checkWinner(char board[SIZE][SIZE], char player);
int  isBoardFull(char board[SIZE][SIZE]);
void clearInputLine(void);

int main(void)
{
    char board[SIZE][SIZE];
    char again = 'y';
    int  scoreX = 0, scoreO = 0, draws = 0;

    printf("=====================================\n");
    printf("        TIC-TAC-TOE (2 PLAYERS)      \n");
    printf("=====================================\n");
    printf("Player 1 = X    Player 2 = O\n");

    while (again == 'y' || again == 'Y')
    {
        char current = 'X';
        int  playerNo = 1;
        int  gameOver = 0;

        initBoard(board);

        while (!gameOver)
        {
            displayBoard(board);
            getMove(board, current, playerNo);

            if (checkWinner(board, current))
            {
                displayBoard(board);
                printf("\n*** Player %d (%c) wins! ***\n", playerNo, current);
                if (current == 'X') scoreX++; else scoreO++;
                gameOver = 1;
            }
            else if (isBoardFull(board))
            {
                displayBoard(board);
                printf("\nIt's a draw!\n");
                draws++;
                gameOver = 1;
            }
            else
            {
                /* switch turn */
                if (current == 'X') { current = 'O'; playerNo = 2; }
                else                { current = 'X'; playerNo = 1; }
            }
        }

        printf("\n------------- SCOREBOARD -------------\n");
        printf("Player 1 (X): %d | Player 2 (O): %d | Draws: %d\n", scoreX, scoreO, draws);
        printf("--------------------------------------\n");

        printf("\nPlay again? (y/n): ");
        if (scanf(" %c", &again) != 1) break;
        clearInputLine();
    }

    printf("\nThanks for playing! Final score -> X: %d, O: %d, Draws: %d\n",
           scoreX, scoreO, draws);
    return 0;
}

/* Fill the board with cell numbers '1' to '9' */
void initBoard(char board[SIZE][SIZE])
{
    char n = '1';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = n++;
}

/* Print the board */
void displayBoard(char board[SIZE][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("     %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1)
            printf("    ---+---+---\n");
    }
    printf("\n");
}

/* Ask the current player for a cell (1-9) until a valid one is chosen */
int getMove(char board[SIZE][SIZE], char player, int playerNo)
{
    int choice, row, col;

    while (1)
    {
        printf("Player %d (%c), enter a cell number (1-9): ", playerNo, player);

        int rc = scanf("%d", &choice);
        if (rc == EOF)
        {
            printf("\nInput closed. Exiting game.\n");
            exit(0);
        }
        if (rc != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputLine();
            continue;
        }
        clearInputLine();

        if (choice < 1 || choice > 9)
        {
            printf("Number must be between 1 and 9.\n");
            continue;
        }

        row = (choice - 1) / SIZE;
        col = (choice - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("That cell is already taken. Try another.\n");
            continue;
        }

        board[row][col] = player;
        return choice;
    }
}

/* Return 1 if the given player has three in a row, column or diagonal */
int checkWinner(char board[SIZE][SIZE], char p)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return 1; /* row    */
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return 1; /* column */
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return 1;     /* diagonal */
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return 1;     /* diagonal */
    return 0;
}

/* Return 1 when no empty cells are left */
int isBoardFull(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

/* Discard leftover characters in the input buffer */
void clearInputLine(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
