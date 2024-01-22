// main.c

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "game.h"

char **board;
gameInfo game;

typedef enum
{
    BLACK = 0, BLUE = 1, GREEN = 2,
    AQUA = 3, RED = 4, PURPLE = 5,
    YELLOW = 6, WHITE = 7, GRAY = 8, 
    LIGHT_BLUE = 9, LIGHT_GREEN = 10,
    LIGHT_AQUA = 11, LIGHT_RED = 12, 
    LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
} ConsoleColors;

int main()
{
    setTextColor(LIGHT_RED);
    printf("Welcome to Qouridor!\n");

    setTextColor(LIGHT_GREEN);
    int size;
    printf("Please enter the size of board: ");
    scanf("%d", &size); // user size

    size = (2 * size) - 1; // real size
    game.size = size;

    board = (char**)malloc(size * sizeof(char*));

    if (board == NULL)
    {
        printf("We can't allocate this memory for your board...\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        board[i] = (char*)malloc(size * sizeof(char));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i % 2 == 0 && j % 2 == 0) board[i][j] = ' ';
            else if (i % 2 != 0 && j % 2 == 0) board[i][j] = '-';
            else if (i % 2 != 0 && j % 2 != 0) board[i][j] = '+';
            else if (i % 2 == 0 && j % 2 != 0) board[i][j] = ':';
        }
    }

    setTextColor(AQUA);
    printf("Please enter the information of players: \n");
    setTextColor(WHITE);
    printf("-----------------\n");

    setTextColor(PURPLE);
    printf("Player1 name: ");
    scanf("%s", game.player1Name);
    getchar();
    printf("Player1 sign: ");
    scanf("%c", &game.player1Sign);
    getchar();
    
    setTextColor(YELLOW);
    printf("Player2 name: ");
    scanf("%s", game.player2Name);
    getchar();
    printf("Player2 sign: ");
    scanf("%c", &game.player2Sign);
    getchar();

    setTextColor(GRAY);
    printf("Count of walls: ");
    scanf("%d", &game.count_wall1);
    game.count_wall2 = game.count_wall1;

    setTextColor(WHITE);
    printf("-----------------\n\n");

    initializeGame(&game);
    printBoard(&game);

    while (1)
    {
        setTextColor(PURPLE);
        printf("%s turn...\n", &game.player1Name);
        playGame(&game, 1);

        printBoard(&game);
        printf("\n");

        if (checkWinner(&game) == 1)
        {
            setTextColor(PURPLE);
            printf("%s is the winner!\n", &game.player1Name);
            setTextColor(WHITE);
            break;
        }

        setTextColor(LIGHT_GREEN);
        printf("%s turn...\n", &game.player2Name);
        playGame(&game, 2);

        printBoard(&game);
        printf("\n");

        if (checkWinner(&game) == 2)
        {
            setTextColor(GREEN);
            printf("%s is the winner!\n", &game.player2Name);
            setTextColor(WHITE);
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }

    free(board);

    return 0;
}

