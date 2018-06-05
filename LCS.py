import os
import time

board = [' ',' ',' ',' ',' ',' ',' ',' ',' ',' ']
player = 1

########win Flags##########
Win = 1
Draw = -1
Running = 0
Stop = 1
###########################
Game = Running
Mark = 'X'

#This Function Draws Game Board
def DrawBoard():
    print(" %c | %c | %c " % (board[1],board[2],board[3]))
    print("___|___|___")
    print(" %c | %c | %c " % (board[4],board[5],board[6]))
    print("___|___|___")
    print(" %c | %c | %c " % (board[7],board[8],board[9]))
    print("   |   |   ")

#This Function Checks position is empty or not
def CheckPosition(x):
    if(board[x] == ' '):
        return True
    else:
        return False

#This Function Checks player has won or not
def CheckWin():
    global Game
    #Horizontal winning condition
    if(board[1] == board[2] and board[2] == board[3] and board[1] != ' '):
        Game = Win
    elif(board[4] == board[5] and board[5] == board[6] and board[4] != ' '):
        Game = Win
    elif(board[7] == board[8] and board[8] == board[9] and board[7] != ' '):
        Game = Win
    #Vertical Winning Condition
    elif(board[1] == board[4] and board[4] == board[7] and board[1] != ' '):
        Game = Win
    elif(board[2] == board[5] and board[5] == board[8] and board[2] != ' '):
        Game = Win
    elif(board[3] == board[6] and board[6] == board[9] and board[3] != ' '):
        Game=Win
    #Diagonal Winning Condition
    elif(board[1] == board[5] and board[5] == board[9] and board[5] != ' '):
        Game = Win
    elif(board[3] == board[5] and board[5] == board[7] and board[5] != ' '):
        Game=Win
    #Match Tie or Draw Condition
    elif(board[1]!=' ' and board[2]!=' ' and board[3]!=' ' and board[4]!=' ' and board[5]!=' ' and board[6]!=' ' and board[7]!=' ' and board[8]!=' ' and board[9]!=' '):
        Game=Draw
    else:
        Game=Running

#This function checks if player has played a valid move or not
def isValid(cell,restrictedPos):
    if (cell==restrictedPos):
        return False
    else:
        return True



print("Player 1 [X] --- Player 2 [O]\n")
restrictX=int(input("Enter a position where X cannot play : "))
restrictO=int(input("Enter a position where O cannot play : "))
print("\n")


while(Game == Running):
    os.system('cls')
    DrawBoard()
    print("\n")
    print("Restricted cell for X : %d " %(restrictX))
    print("Restricted cell for O : %d " % (restrictO))
    if(player % 2 != 0):
        print("Player 1's chance(X)")
        Mark = 'X'
    else:
        print("Player 2's chance(O)")
        Mark = 'O'
    choice = int(input("Enter the position between [1-9] where you want to mark : "))
    if(Mark=='X'):
        if(isValid(choice,restrictX)):
            if (CheckPosition(choice)):
                board[choice] = Mark
                player += 1
                CheckWin()
        else:
            print("\n")
            print("******You cannot play in a restricted cell******")
            print("\n")
            time.sleep(2)

    if (Mark == 'O'):
        if (isValid(choice, restrictO)):
            if (CheckPosition(choice)):
                board[choice] = Mark
                player += 1
                CheckWin()
        else:
            print("\n")
            print("******You cannot play in a restricted cell******")
            print("\n")
            time.sleep(2)




os.system('cls')
DrawBoard()
if(Game==Draw):
    print("Game Draw")
elif(Game==Win):
    player-=1
    if(player%2!=0):
        print("X Won")
    else:
        print("O Won")
