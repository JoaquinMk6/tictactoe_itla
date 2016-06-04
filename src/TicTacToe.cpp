#include "TicTacToe.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//I create new variables: int plays = 0;and char winner;
char board[3][3]; //Possible values are X, O and _ (for blank positions)
char player = 'X';
int plays = 0;
char winner;

bool isAvailable(int row, int column)
 {
    if (board[row][column] != '_' )
 	{
     cout << "That plays has already been done" << endl;
     return false;
    }
    return true;
 }

//Give initial values to the board matrix

void init()
{
	for(int i = 0 ; i < 3 ; i++)
	{
        for(int j = 0 ; j < 3 ; j++)


		{
			board[i][j] = '_';
		}
	}
}

void clearScreen()
{
	#ifdef _WIN32
    system("cls");
	#else
	system("clear");
	#endif
}

bool validate(int number)
{
	if(number >= 1 && number <= 3)
	{
		return true;
	}else
	{
		cout << "Please pick a value between 1 and 3" << endl;
		return  false;
	}
}


// In this part I Implement this methods to verify if any player has won the match of it's being a tie.

bool gameover()
{
    plays++;
    if (plays > 5) {
        if (board [0][0] == board [0][1] && board [0][1] == board [0][2] && board [0][1] != '_')
            {
            cout << "Player " << winner << " win." << endl;
                return true;
            }
            else if (board [1][0] == board [1][1] && board [1][1] == board [1][2] && board [1][1] != '_')
            {
            cout << "Player " << winner << " win." << endl;
               return true;
            }
            else if (board [2][0] == board [2][1] && board [2][1] == board [2][2] && board [2][1] != '_')
            {
            cout << "Player " << winner << " win." << endl;
                return true;
            }
            else if (board [0][0] == board [1][0] && board [1][0] == board [2][0] && board [1][0])
            {
            cout << "Player " << winner << " win." << endl;
                return true;
            }
            else if (board [0][1] == board [1][1] && board [1][1] == board [2][1] && board [1][1] != '_')
            {
            cout << "Player " << winner << " win." << endl;
                return true;
            }
            else if (board [0][2] == board [1][2] && board [1][2] == board [2][2] && board [1][2] != '_')
            {
            cout << "Player " << winner << " win." << endl;
                return true;
            }
            else if (board [0][0] == board [1][1] && board [1][1] == board [2][2] & board [1][1] != '_')
            {
            cout << "Player " << winner << "win." << endl;
                return true;
            }
            else if (board [0][2] == board [1][1] && board [1][1] == board [2][0] && board [1][1] != '_')
            {
            cout << "Player " << winner << "win." << endl;
                return true;
            }
        }
        return false;
    }

	//TODO: Implement this method,verify if any player has won the match of it's being a tie.
	//Return true if the game is over. Print message informing the user about what just happened.
	if(false){ // change this with a real condition
		cout << "You loose" << endl;
	}
	return false;
}

bool isValidInput(istream& in){
	if(in.fail())
	{
		cout <<"Only numbers are accepted" << endl;
	    in.clear();
	    in.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
	    return false;
	}else
	{
		return true;
	}
}

void showBoard()
{
	while(!gameover())
	{
	    winner = player == 'X' ? 'X' : 'O';
		clearScreen();
		int row = 0;
		int column = 0;

		cout << "It's " << player << "'s turn" << endl;
		//printing column numbers
		cout << "\t";
		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
		}
		cout << endl;

		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
			for(int j = 0 ; j < 3 ; j++)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl;
		}
		do
		{
			cout << "In what row would you like to play? =>";
			cin >> row;
		}while(!isValidInput(cin) && !validate(row));
		do
		{
			cout << "In what column would you like to play? => ";
			cin >> column;
		}while(!isValidInput(cin) && !validate(column));

		if(isAvailable(row,column))
		{
			board[row - 1][column - 1] = player;
			player = player == 'X' ? 'O' : 'X';
		}else
		{
			cout << "The cell " << row << " , " << column << " is not available" << endl;
		}
	}
}
