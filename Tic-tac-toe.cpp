#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void nextMove(char[][3], int&, int&);
bool checkWin(char[][3]);
bool checkTie(char[][3]);
void printBoard(char[][3]);
bool possibleWinCheck (char [][3], int & , int &, char);

int main(){
    char keepPlaying;

    //The do-while loop continues until the player does not want to play anymore.
    //The keepPlaying variable stores the input from the user to determine if the user wishes to keep playing the game
    do {
        char board[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};

        // This while loop continues until the player or computer wins.
        while(true){
            int rowX = 0, colX = 0, rowO, colO;
            bool repeat = true;
            nextMove(board, rowX, colX);
            board[rowX][colX] = 'X';
            printBoard(board);

            if (checkWin(board)){
               cout << "computer wins \n ";
               break;
            };
            if (checkTie(board)){
              cout << "There is a tie \n";
              break;
            };

            {
                // Checks human move is legal
                while (repeat == true){
                    cout << "What row (0, 1, or 2) would you like to place your O in?" << endl;
                    cin >> rowO;
                    cout << "What column (0, 1, or 2) would you like to place your O in?" << endl;
                    cin >> colO;
                    if ((board[rowO][colO] == 'X') || (board[rowO][colO] == 'O')){
                        repeat = true;
                        cout << "That spot is already taken. Please choose another row and column." << endl;
                    }
                    else if (rowO>2||colO>2||rowO<0||colO<0){
                        repeat = true;
                        cout << "You must choose either 0, 1, or 2. Please enter another row and column." << endl;
                    }
                    else{
                        repeat = false;
                    }
                }

                board[rowO][colO] = 'O';
                printBoard(board);
                if (checkWin(board)){
                    cout << "You win " << endl;
                    break;
                };
                if (checkTie(board)){
                   cout << "There is a tie " << endl;
                   break;
                }
            }
        }

        cout << "Do you want to play again? (Y/N)?" << endl;;
        cin >> keepPlaying;
    } while(keepPlaying == 'Y');
    return 0;
}

//The following function is used to help computer player make correct decision for next move
bool possibleWinCheck (char board[][3], int & i, int &j, char chXO){
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (board[i][j] == '-'){
                board[i][j] = 'X';
                if(checkWin(board)){
                    board[i][j] = 'X';
                    return true;
                }
                else {
                    board[i][j] = '-';
                }
            }
            else{}
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (board[i][j] == '-'){
                board[i][j] = 'O';
                if(checkWin(board)){
                    board[i][j] = 'X';
                    return true;
                }
                else {
                    board[i][j] = '-';
                }
            }
            else{}
        }
    }

    if (board[0][0] == '-'){
        board[0][0] = 'X';
        return true;
    }

    return false;
}

//The following is a major function used to help computer player find a good next move
void nextMove (char board[][3], int &row, int &col)
{
    int i, j;
    bool repeat = true, startRan, firstmove = true;
    char XO;

    startRan = possibleWinCheck(board, i, j, XO);

    if (firstmove == true){
        board[0][0] = 'X';
        firstmove = false;
    }

    if (startRan == false){
        while(repeat){
            srand(time(0));
            row = rand()%3;
            col = rand()%3;
            if ((board[row][col] == 'X') || (board[row][col] == 'O')) {
                repeat = true;
            }
            else{
                repeat = false;
            }
        }
    }
    else{
        return;
    }
}

//The following function check whether there is a winning board
//This function is completely written for you and you do not need to change/update it
bool checkWin(char board[][3])
{
  bool win = false;
  for (int i = 0; i <= 2; i++)
  {

      if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')  win = true; else
      if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')  win = true; else

      if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')  win = true; else
      if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')  win = true;
   }

   if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')  win = true; else
   if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')  win = true;

   if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')  win = true; else
   if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')  win = true;

   //cout << " win in check function " << win << endl;
   return win;
}

//The following function prints the board content
//This function is completely written for you and you do not need to change/update it
void printBoard(char board[][3])       //This function prints the board.
{
    cout << endl;
    for(int row=0; row <=2; row++)
    {
       for(int col=0; col <=2; col++)
       {
           cout << board[row][col];
       }
       cout << endl;
    }
    cout << endl;
}

//The following check whether the board content is a tie
//This function is completely written for you and you do not need to change/update it
bool checkTie(char board[][3])       //This function checks tie.
{

    int count = 0;
    for(int row=0; row <=2; row++)
    {
       for(int col=0; col <=2; col++)
       {
           if ((board [row][col] == 'O') || (board [row][col] == 'X'))  count++ ;
       }
    }
    if (count == 9) return true; else
                    return false;
}
