#define NOMINMAX 
#include <iostream>		// standard library header
#include <stdlib.h>		
#include <conio.h>		// For _getch();
#include <string>		// For writing answers
#include <Windows.h>	
#include <cstdlib>		// for rand() and srand()
#include <ctime>		// for time
#include <vector>		// for vectors
#include <iterator>		// for std::size

/*int getinputfromuser (){

	int integer;
	std::cin >> integer;    
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max()), '\n';
		system("cls");
		std::cout << "That, my friend, is not a number...\n";
		std::cin >> integer;
	}
	return integer;
}
*/

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


void game1() {
	system("cls");
	printBoard();

}


void game2() {
	system("cls");
	printBoard();
}


void menu() {
	std::cout << "\n\n\n[1] Single player vs AI " << std::endl;
	std::cout << "[2] Two players " << std::endl;
	std::cout << "[0] Exit terminal" << std::endl;
	std::cout << "\nInput: ";


	int game;
	
	do
	{
		std::cin >> game;
		switch (game)
		{
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 0:
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cout << "\nPlease select a number [0-2]. ";
			break;
		} 
	
	}
	while (true);
}


int main() 
{

	system("cls");
	std::cout << "\t\t\t\t\t" << "----------------------------------" << std::endl;
	std::cout << "\t\t\t\t\t" << "|                                |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|          TIC TAC TOE           |" << std::endl;
	std::cout << "\t\t\t\t\t" << "|             v 1.0              |" << std::endl;
	std::cout << "\t\t\t\t\t" << "----------------------------------" << std::endl;

	std::cout << '\n' << "Welcome to a simplistic version of Tic Tac Toe.  " << std::endl;

	
	//Main menu
			//Add players
				//Add 1 player vs AI
					//Let player 1 be X (first to go) and AI to be O (second player)
						//AI can be rand or Srand. 
						//Boolean
				//Add 2 players
					//Player 1 is X (first to go) and Player 2 is O (second to go)
						//Boolean


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