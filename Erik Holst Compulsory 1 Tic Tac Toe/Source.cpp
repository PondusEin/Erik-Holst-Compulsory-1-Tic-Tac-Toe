#include <iostream>
#include <stdlib.h>
#include <conio.h>		// For _getch();
#include <string>		// For writing answers
#include <Windows.h>
#include <cstdlib>		// for rand() and srand()
#include <ctime>		// for time
#include <vector>		// for vectors
#include <algorithm>



void printBoard() 
{
	const int size = 10;
	int myarray[size] = {};
	std::vector <char> board = { '1','2','3','4','5','6','7','8','9' }; //ikke int.

	  for (int i = 0; i < board.size(); i++)
	  {
		  if (i % 3 == 0)
		  {
			  std::cout << '\n' << "-------------";
			  std::cout << "\n" << '|';  
		  }
		  std::cout << ' ' << board[i] << ' '; //ikke 0
		  std::cout << "|";
	  }
	  std::cout << '\n' << "-------------";
}


void game() {

}

int main() {

	std::cout << "\t\t\t\t\t" << "----------------------------------" << std::endl;
	std::cout << "\t\t\t\t\t" << "|                                |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|          TIC TAC TOE           |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|             v 1.0              |" << std::endl;
	std::cout << "\t\t\t\t\t" << "----------------------------------" << std::endl;

	std::cout << '\n' << "Welcome to a simplistic version of Tic Tac Toe.  " << std::endl;


	printBoard();
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