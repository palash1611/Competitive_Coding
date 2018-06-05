#include <iostream>
#include<iomanip> // used for defining manipulator functions resetiosflags() ,
                  // setiosflags() , setbase() , setfill() , setprecision() , and setw() etc.
using namespace std;

class TicTacToe
{
public:
  void printBoard(); // Print Board on Screen.
  void getMove1(int); // Get Person 1's move.
  void getMove2(int); // Get Person 2's move.
  bool isValidMove(int,int); //Checks if there is already a x or o in that place.
  bool detWinner1(); //check if person 1 is a winner or not.
  bool detWinner2(); // check if person 2 is a winner or not.
  bool determineDraw();
  void reset(); // reset the board.
  TicTacToe(); //constructor.
private: char board[3][3];
};

void TicTacToe::reset() //All empty spaces denoted by *
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      board[i][j]=' ';
    }
  }
}

void TicTacToe::printBoard()
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<setw(3)<<board[i][j]<<" ";
    }
    cout<<endl<<endl;
  }
}

TicTacToe::TicTacToe() //constructor definition
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      board[i][j]=' ';
    }
  }
}

void TicTacToe::getMove1(int num)
{
  bool Validate=false;

  switch (num) {
         case 1: validate=isValidMove(0,0);
                  if(validate==true)
                    board[0][0]='X';
                  break;
         case 2: validate=isValidMove(0,1);
                  if(validate==true)
                    board[0][1]='X';
                  break;
         case 3: validate=isValidMove(0,2);
                 if(validate==true)
                    board[0][2]='X';
                 break;
         case 4: validate=isValidMove(1,0);
                if(validate==true)
                  board[1][0]='X';
                break;
         case 5: validate=isValidMove(1,1);
                  if(validate==true)
                    board[1][1]='X';
                  break;
         case 6: validate=isValidMove(1,2);
                  if(validate==true)
                    board[1][2]='X';
                  break;
         case 7: validate=isValidMove(2,0);
                 if(validate==true)
                    board[2][0]='X';
                 break;
         case 8: validate=isValidMove(2,1);
                if(validate==true)
                  board[2][1]='X';
                break;
         case 9: validate=isValidMove(2,2);
                 if(validate==true)
                   board[2][2]='X';
                break;
         default : cout<<"Invalid Input"<<endl;
                break;
  }
}

bool TicTacToe::isValidMove(int row, int col)
{
  if(board[row][col]=='X' || board[row][col]=='O')
    return false;
  else
    return true;
}

void TicTacToe::getMove2(int num)
{
  bool Validate=false;

  switch (num) {
         case 1: validate=isValidMove(0,0);
                  if(validate==true)
                    board[0][0]='O';
                  break;
         case 2: validate=isValidMove(0,1);
                  if(validate==true)
                    board[0][1]='O';
                  break;
         case 3: validate=isValidMove(0,2);
                 if(validate==true)
                    board[0][2]='O';
                 break;
         case 4: validate=isValidMove(1,0);
                if(validate==true)
                  board[1][0]='O';
                break;
         case 5: validate=isValidMove(1,1);
                  if(validate==true)
                    board[1][1]='O';
                  break;
         case 6: validate=isValidMove(1,2);
                  if(validate==true)
                    board[1][2]='O';
                  break;
         case 7: validate=isValidMove(2,0);
                 if(validate==true)
                    board[2][0]='O';
                 break;
         case 8: validate=isValidMove(2,1);
                if(validate==true)
                  board[2][1]='O';
                break;
         case 9: validate=isValidMove(2,2);
                 if(validate==true)
                   board[2][2]='O';
                break;
         default : cout<<"Invalid Input"<<endl;
                break;
  }
}

bool TicTacToe::detWinner1()
{
  for(int row=0;row<3;row++)
  {
    int count=0;
    for(int col=0;col<3;col++)
    {
      if(board[row][col]=='X')
        count+=1;

      if (count>=3)
      return true;

    }
  }

  for(int col=0;col<3;col++)
  {
    int counter=0;
    for(int row=0;row<3;row++)
    {
      if(board[row][col]=='X')
        count+=1;

      if (count>=3)
      return true;

    }
  }

  if(board[0][0]=='X' && board[1][1]=='X')
    if(board[2][2]=='X')
      return true;

  if(board[0][2]=='X' && board[1][1]=='X')
    if(board[2][0]=='X')
      return true;

  return false;
}

bool TicTacToe::detWinner1()
{
  for(int row=0;row<3;row++)
  {
    int count=0;
    for(int col=0;col<3;col++)
    {
      if(board[row][col]=='O')
        count+=1;

      if (count>=3)
      return true;

    }
  }

  for(int col=0;col<3;col++)
  {
    int counter=0;
    for(int row=0;row<3;row++)
    {
      if(board[row][col]=='O')
        count+=1;

      if (count>=3)
      return true;

    }
  }

  if(board[0][0]=='O' && board[1][1]=='O')
    if(board[2][2]=='O')
      return true;

  if(board[0][2]=='O' && board[1][1]=='O')
    if(board[2][0]=='O')
      return true;

  return false;
}

bool TicTacToe::determineDraw()
{
  for(int row=0;row<3;row++)
  {
    for(int col=0;col<3;col++)
    {
      if(board[row][col]==' ')
        return false;
    }
  }

  return true;
}

void instructions();
void play();

int main()
{

  int choice;

  do
  {
      cout<<"Tic Tac Toe"<<endl;
      cout<<"For instructions enter 1"<<endl;
      cout<<"To play enter 2"<<endl;
      cout<<"To exit enter 9"<<endl;
      cin>>choice;

      switch (choice) {
        case 1: instructions();
                  break;
        case 2: play();
                  break;
      }
  }while(choice!=9);

  return 0;
}

void instructions()
{
  cout<<endl;
  cout<<"Rules"<<endl;

}

void play()
{
  int num;
  static TicTacToe board;
  bool status=false;

  while (status==false) {
      cout<<"\nEnter play (player 1): "<<endl;
      cin>>num;
      if(!cin)
      {
        cin.clear();
        cin.ignore(100,'\n');
      }
  }
}
