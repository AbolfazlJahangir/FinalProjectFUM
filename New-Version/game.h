// game.h

#ifndef GAME_H
#define GAME_H

#define MAX_LEN_NAME 30

extern char **board;

typedef struct
{
    int size;
    char player1Sign;
    char player2Sign;
    char player1Name[MAX_LEN_NAME];
    char player2Name[MAX_LEN_NAME];
    int position1[2];
    int position2[2];
    int count_wall1;
    int count_wall2;
} gameInfo;

extern gameInfo game;

void initializeGame(gameInfo *game);

void printBoard(gameInfo *game);

int isValidMove(gameInfo *game, int direction, int player);

int isValidWall(gameInfo *game, int x, int y, char model);

int checkWinner(gameInfo *game);

void changePosition(gameInfo *game, int player, char sign);

int getMove(gameInfo *game, int direction, int player);

int getWall(gameInfo *game, int x, int y, char model);

void playGame(gameInfo *game, int player);


#endif

