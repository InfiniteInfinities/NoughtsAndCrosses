/**
* Noughts and Crosses Game in C++
* @author Maria Merkulova
* @inspiration {@link https://www.stechies.com/tic-tac-toe-cpp/}
*/

#include <iostream>
using namespace std;

//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board
void display_board(){

    //Rander Game Board LAYOUT

    cout<<" PLAYER - 1 [X]\n PLAYER - 2 [O]\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
}

//Function to get the player input and update the board
void player_turn(){
    if(turn == 'X'){
        cout<<"Player - 1 turn : \n";
    }
    else{
        cout<<"Player - 2 turn : \n";
    }

    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be updated

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move\n";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!\n Please choose another!!\n";
        player_turn();
    }
}

//Function to get the game status e.g. GAME WON, GAME DRAW, GAME CONTINUES
bool gameon(){
    //checking the win for Rows and Columns
    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking whether there are any free spaces
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    //if no conditions met, must be draw
    draw = true;
    return false;
}


int main()
{
    cout<<"NOUGHTS AND CROSSES\n";
    while(gameon()){
        display_board();
        player_turn();
    }
    if(turn == 'X' && !draw){
        cout<<"Congratulations!Player 2 has won the game\n";
    }
    else if(turn == 'O' && !draw){
        cout<<"Congratulations!Player 1 has won the game\n";
    }
    else
        cout<<"GAME DRAW!!!\n";
} 
