player1 = "X"
player2 = "Y"

wall1 = 10
wall2 = 10

x1, y1 = (0, 4)
x2, y2 = (8, 4)

row_move = 9
column_move = 9

board = [[" "] * row_move for i in range(row_move)]

# موقعیت اولیه بازیکن ها در برد بازی
board[x1][y1] = player1
board[x2][y2] = player2

board_wall = [["-"] * (row_move - 1) for i in range(row_move - 1)]

# تعیین نوبت دور اول
turn1 = True
turn2 = False


# نمایش برد بازی
def printBoard():

    print(f" {board[0][0]} | {board[0][1]} | {board[0][2]} | {board[0][3]} | {board[0][4]} | {board[0][5]} | {board[0][6]} | {board[0][7]} | {board[0][8]} ")
    print(f"-{board_wall[0][0]}-|-{board_wall[0][1]}-|-{board_wall[0][2]}-|-{board_wall[0][3]}-|-{board_wall[0][4]}-|-{board_wall[0][5]}-|-{board_wall[0][6]}-|-{board_wall[0][7]}-|---")
    
    print(f" {board[1][0]} | {board[1][1]} | {board[1][2]} | {board[1][3]} | {board[1][4]} | {board[1][5]} | {board[1][6]} | {board[1][7]} | {board[1][8]} ")
    print(f"-{board_wall[1][0]}-|-{board_wall[1][1]}-|-{board_wall[1][2]}-|-{board_wall[1][3]}-|-{board_wall[1][4]}-|-{board_wall[1][5]}-|-{board_wall[1][6]}-|-{board_wall[1][7]}-|---")
    
    print(f" {board[2][0]} | {board[2][1]} | {board[2][2]} | {board[2][3]} | {board[2][4]} | {board[2][5]} | {board[2][6]} | {board[2][7]} | {board[2][8]} ")
    print(f"-{board_wall[2][0]}-|-{board_wall[2][1]}-|-{board_wall[2][2]}-|-{board_wall[2][3]}-|-{board_wall[2][4]}-|-{board_wall[2][5]}-|-{board_wall[2][6]}-|-{board_wall[2][7]}-|---")
    
    print(f" {board[3][0]} | {board[3][1]} | {board[3][2]} | {board[3][3]} | {board[3][4]} | {board[3][5]} | {board[3][6]} | {board[3][7]} | {board[3][8]} ")
    print(f"-{board_wall[3][0]}-|-{board_wall[3][1]}-|-{board_wall[3][2]}-|-{board_wall[3][3]}-|-{board_wall[3][4]}-|-{board_wall[3][5]}-|-{board_wall[3][6]}-|-{board_wall[3][7]}-|---")
    
    print(f" {board[4][0]} | {board[4][1]} | {board[4][2]} | {board[4][3]} | {board[4][4]} | {board[4][5]} | {board[4][6]} | {board[4][7]} | {board[4][8]} ")
    print(f"-{board_wall[4][0]}-|-{board_wall[4][1]}-|-{board_wall[4][2]}-|-{board_wall[4][3]}-|-{board_wall[4][4]}-|-{board_wall[4][5]}-|-{board_wall[4][6]}-|-{board_wall[4][7]}-|---")
    
    print(f" {board[5][0]} | {board[5][1]} | {board[5][2]} | {board[5][3]} | {board[5][4]} | {board[5][5]} | {board[5][6]} | {board[5][7]} | {board[5][8]} ")
    print(f"-{board_wall[5][0]}-|-{board_wall[5][1]}-|-{board_wall[5][2]}-|-{board_wall[5][3]}-|-{board_wall[5][4]}-|-{board_wall[5][5]}-|-{board_wall[5][6]}-|-{board_wall[5][7]}-|---")
    
    print(f" {board[6][0]} | {board[6][1]} | {board[6][2]} | {board[6][3]} | {board[6][4]} | {board[6][5]} | {board[6][6]} | {board[6][7]} | {board[6][8]} ")
    print(f"-{board_wall[6][0]}-|-{board_wall[6][1]}-|-{board_wall[6][2]}-|-{board_wall[6][3]}-|-{board_wall[6][4]}-|-{board_wall[6][5]}-|-{board_wall[6][6]}-|-{board_wall[6][7]}-|---")
    
    print(f" {board[7][0]} | {board[7][1]} | {board[7][2]} | {board[7][3]} | {board[7][4]} | {board[7][5]} | {board[7][6]} | {board[7][7]} | {board[7][8]} ")
    print(f"-{board_wall[7][0]}-|-{board_wall[7][1]}-|-{board_wall[7][2]}-|-{board_wall[7][3]}-|-{board_wall[7][4]}-|-{board_wall[7][5]}-|-{board_wall[7][6]}-|-{board_wall[7][7]}-|---")
    
    print(f" {board[8][0]} | {board[8][1]} | {board[8][2]} | {board[8][3]} | {board[8][4]} | {board[8][5]} | {board[8][6]} | {board[8][7]} | {board[8][8]} ")


# حرکت بازیکن ها روی مکان های مجاز
def emptySpacesMove(x, y):

    if x != x1 and x != x2 and y != y1 and y != y2:
        return True
    else:
        return False


def emptySpacesWall(x, y):
    pass


def checkWinner():

    if x1 == 8 or x2 == 0:
        if x1 == 8:
            return 1
        else:
            return 2
    elif wall1 == 0 and wall2 == 0 and x1 != 8 and x2 != 0:
        return "Tie"
    else:
        return False


def play():
    global board, turn1, turn2, x1, y1, x2, y2

    while checkWinner() is False:
        if turn1 is True:
            move1 = int(input("Player1 turn --> up(1) down(2) right(3) left(4): "))
            if move1 == 1:
                board[x1][y1] = " "
                board[x1 - 1][y1] = player1
                x1 -= 1
            elif move1 == 2:
                board[x1][y1] = " "
                board[x1 + 1][y1] = player1
                x1 += 1
            elif move1 == 3:
                board[x1][y1] = " "
                board[x1][y1 + 1] = player1
                y1 += 1
            elif move1 == 4:
                board[x1][y1] = " "
                board[x1][y1 - 1] = player1
                y1 -= 1
            else:
                continue
            turn1 = False
            turn2 = True
            printBoard()
        else:
            move2 = int(input("Player2 turn --> up(1) down(2) right(3) left(4): "))
            if move2 == 1:
                board[x2][y2] = " "
                board[x2 - 1][y2] = player2
                x2 -= 1
            elif move2 == 2:
                board[x2][y2] = " "
                board[x2 + 1][y2] = player2
                x2 += 1
            elif move2 == 3:
                board[x2][y2] = " "
                board[x2][y2 + 1] = player2
                y2 += 1
            elif move2 == 4:
                board[x2][y2] = " "
                board[x2][y2 - 1] = player2
                y2 -= 1
            else:
                continue
            turn2 = False
            turn1 = True
            printBoard()


printBoard()
play()
if checkWinner() == 1:
    print("Player1 won!")
elif checkWinner == 2:
    print("Player2 won!")
else:
    print("It's Tie!")
