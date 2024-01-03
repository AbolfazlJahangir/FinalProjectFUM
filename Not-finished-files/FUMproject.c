#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define WHITE "\x1b[0m"
#define ORANGE "\x1b[38;5;208m"
#define CYAN "\x1b[38;5;6m"

char board[9][9];
struct game
{
    char player1;
    int wall1, x1, y1;

    char player2;
    int wall2, x2, y2;
};

void createBoard();
void printBoard();

int main()
{
    createBoard();
    printBoard();
    return 0;
}

void createBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4],
    board[0][5], board[0][6], board[0][7], board[0][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[1][0], board[1][1], board[2][2], board[3][3], board[4][4],
    board[5][5], board[6][6], board[7][7], board[8][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4],
    board[2][5], board[2][6], board[2][7], board[2][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4],
    board[3][5], board[3][6], board[3][7], board[3][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4],
    board[4][5], board[4][6], board[4][7], board[4][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4],
    board[5][5], board[5][6], board[5][7], board[5][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4],
    board[6][5], board[6][6], board[6][7], board[6][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4],
    board[7][5], board[7][6], board[7][7], board[7][8]);
    printf("\n---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c ", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4],
    board[8][5], board[8][6], board[8][7], board[8][8]);
    
}