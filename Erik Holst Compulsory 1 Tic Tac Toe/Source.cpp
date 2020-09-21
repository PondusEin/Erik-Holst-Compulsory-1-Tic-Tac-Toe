#define NOMINMAX 
#include <iostream>		// standard library header
#include <conio.h>		// For _getch();
#include <cstdlib>		// for rand() and srand()
#include <ctime>		// for time
#include <vector>		// for vectors

std::vector <int> invalidchoice;
std::vector	<char> board = { '1','2','3','4','5','6','7','8','9' };
bool playeroneturn = true;

int getinputfromuser (){

	int integer;
	std::cin >> integer;;
	while (std::cin.fail() || integer>9 || integer<=0 || std::count(invalidchoice.begin(), invalidchoice.end(), integer)==true) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max()), '\n';
		system("cls");
		std::cout << "Error" << integer << "is not a valid number.\n";
		std::cin >> integer;
	}
	invalidchoice.emplace_back(integer);
	return integer;
}

void oneplayer()
{
	if (playeroneturn == true)
	{
		playeroneturn = false;
		getinputfromuser();
	}
	else if (playeroneturn == false) 
	{
		std::srand(time(nullptr));
	}
}

void twoplayer()
{
	if (playeroneturn == true)
	{
		std::cout << "Player 1's [X] turn: ";
		board[getinputfromuser() - 1] = 'X';
		playeroneturn = false;
	}
	else if (playeroneturn == false)
	{
		std::cout << "Player 2's [O] turn: ";
		board[getinputfromuser() - 1] = 'O';
		playeroneturn = true;
	} 
}

bool checkwin() 
{
	if (board[0] == board[1] && board[1] == board[2]) { 
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5]) {
		return true;
	}
	else if (board[6] == board[7] && board[7] == board[8]) {
		return true;
	}
	else if (board[0] == board[3] && board[3] == board[6]) {
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7]) {
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8]) {
		return true;
	}
	else if (board[0] == board[4] && board[4] == board[8]) {
		return true;
	}
	else if (board[2] == board[4] && board[4] == board[6]) {
		return true;
	}
	else
	{
		return false;
	}
	
}

void printBoard() 
{
	system("cls");
	for (int i = 0; i < board.size(); i+=3){
		std::cout << " " << board.at(i) << " | " << board.at(i + 1) << " | " << board.at(i + 2) << " " << std::endl;
		if (i < 6)
			std::cout << "---|---|---" << std::endl;
	  }
	  std::cout << std::endl;
}

void checkmark() 
{

}

void game_AI() 
{
	while (checkwin() == false && invalidchoice.size() < 9)
	{
		//system("cls");
		printBoard();
		oneplayer();
	}
}

void game_2_players() 
{
	while (checkwin() == false && invalidchoice.size() < 9 )
	
	{
		//system("cls");
		printBoard();
		twoplayer();
	}
	if (checkwin() == true) 
		{
		printBoard();
		int player;
		if (playeroneturn != true) {
			std::cout << "Congratulations Player one, you are the winner";
		}
			else if (playeroneturn == true) 
			{
			std::cout << "Congratulations Player 2, you are the winner";
			}
		}
}

void menu() 
{
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
			game_AI();
			break;
		case 2:
			game_2_players();
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

	std::cout << "\n\t\t\t\t" << "Welcome to a simplistic version of Tic Tac Toe.  " << std::endl;


	menu();

	
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
		//Replay same scenario.
			// If not, then go back to main menu
		//Exit game if players wants to. 
			//Go back to Main menu
				//If else scenario

	return 0;
}