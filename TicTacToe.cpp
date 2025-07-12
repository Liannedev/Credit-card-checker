#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *board);
void handlePlayerMove(char *board, char player);
void handleComputerMove(char *board, char computer);
bool checkWinner(char *board, char player, char computer);
bool isBoardFull(char *board);


int main(){
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
     drawBoard(board);


     while(running){
        handlePlayerMove(board, player);
        drawBoard(board);
        if(checkWinner(board, player, computer)){
            running = false;
            break;
        } else if (isBoardFull(board)){
            running = false;
            break;
        }

        handleComputerMove(board, computer);
        drawBoard(board);
        if(checkWinner(board, player, computer)){
            running = false;
            break;
        } else if (isBoardFull(board)){
            running = false;
            break;
        }
     }

    cout << "THANKS FOR PLAYING! \n";
    return 0;
}  

void drawBoard(char *board){
    cout << endl;
  
    cout<< "     |     |     " << endl;
    cout<< "  " << board[0] << "  |  " << board[1] << "  |  " <<board[2] << "  " << endl;
    cout<< "_____|_____|_____" << endl;
    cout<< "     |     |     " << endl;
    cout<< "  " << board[3] << "  |  " << board[4] << "  |  " <<board[5] << "  " << endl;
    cout<< "_____|_____|_____" << endl;
    cout<< "     |     |     " << endl;
    cout<< "  " << board[6] << "  |  " << board[7] << "  |  " <<board[8] << "  " << endl;
    cout<< "     |     |     " << endl;
    
    cout << endl;

};

void handlePlayerMove(char *board, char player){
    int number;
    srand(time(0));

    do{
    cout << "Enter a number to put a marker (1-9) ";
    cin >> number;
    number --;

    if(board[number] == ' '){
        board[number] = player;
        break;
    }
    } while (number < 0 || number > 8);

};
void handleComputerMove(char *board, char computer){
   int num;
   
    do{ 
        num = rand() % 9;
    } while (board[num] != ' ');
   
    board[num] = computer;

}

bool checkWinner(char *board, char player, char computer){
     
     if(board[0] != ' ' && board[0] == board[1] &&  board[1] == board[2]){
        board[0] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]){
        board[3] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8]){
        board[6] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6]){
        board[0] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]){
        board[1] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8]){
        board[2] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]){
        board[0] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]){
        board[2] == player ? cout << "YOU WIN! \n" : cout << "YOU LOSE!\n";
     } else {
        return false;
     }
 
    return true;
};
bool isBoardFull(char *board){
    
    for(int i = 0; i < 9; i++){
         if (board[i] == ' '){
            return false;
        } 
    }

    cout << "IT'S A TIE! \n";
    return true;
    
    
};
