#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time



void printBoard() 
{
	char board[5][16] =
	{
		{"---------------"},
		{'|', board[0], '|', board[1], '|', board[2], '|' },
		{'|', board[3], '|', board[4], '|', board[5], '|' },
		{'|', board[6], '|', board[7], '|', board[8], '|' },
		{"---------------"},
	}
}


void game() {

}

int main() {

	std::cout << "\t\t\t\t\t" << "----------------------------------" << std::endl;
	std::cout << "\t\t\t\t\t" << "|                                |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|          TIC TAC TOE           |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|                                |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|          By Erik Holst         |" << std::endl;
	std::cout << "\t\t\t\t\t" << "----------------------------------" << std::endl;

	//Main menu
			//Add players
				//Add 1 player vs AI
					//Let player 1 be X (first to go) and AI to be O (second player)
						//AI can be rand or Srand. 
						//Boolean
				//Add 2 players
					//Player 1 is X (first to go) and Player 2 is O (second to go)
						//Boolean
			//Exit terminal in main menu
				//Switch case (case 0)

	//Add Tic tac toe board
		//Use vector to conditon where the numbers are
		//Add X and O to the board and remove previous board.
			//(cls)
	
	//Win conditions
		//Which row is straight line
			//Name winner in the text
		//If the game is a draw
		//highscores and number of games played

	//Possibility to replay game. 
		//Exit game if players wants to. 
			//Go back to Main menu
				//If else scenario


	
	return 0;
}