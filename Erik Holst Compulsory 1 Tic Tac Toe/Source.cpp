#define NOMINMAX 
#include <iostream>		// standard library header
#include <conio.h>		// For _getch();
#include <cstdlib>		// for rand() and srand()
#include <ctime>		// for time
#include <vector>		// for vectors
#include <string>

std::vector <int> invalidchoice;
std::vector	<char> board = { '1','2','3','4','5','6','7','8','9' };
bool playeroneturn = true;
int replaygame{ 1 };
bool fixproblem = true;

void clearboard() {
	invalidchoice.clear();
	for (int i = 1; i <= 9; i++)
	{
		char replace = '0' + i;
		board[i - 1] = replace;
	}
}

void replaysystem() {
	std::cout << "Would you like to play again?\nReplay same game [1]\nExit game [0]" << std::endl;

	do
	{
		std::cin >> replaygame;
		switch (replaygame)
		{
		case 1:
			clearboard();
			fixproblem = false;
			break;
		case 0:
			exit(1);
			break;
		default:
			std::cout << "\nPlease select a number [0-1]. ";
			break;
		}
	} while (fixproblem == true);
}

int getinputfromuser (){
	int integer;
	std::cin >> integer;;
	while (std::cin.fail() || integer>9 || integer<=0 || 
		std::count(invalidchoice.begin(), invalidchoice.end(), integer)==true) {
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
		std::cout << "Player's [X] turn: ";
		board[getinputfromuser() - 1] = 'X';
		playeroneturn = false;
	}
	else if (playeroneturn == false) 
	{
		std::srand(time(nullptr));
		int randomaichoice = rand() % 9 + 1;
		while (std::cin.fail() || randomaichoice > 9 || randomaichoice <= 0
			|| std::count(invalidchoice.begin(), invalidchoice.end(), randomaichoice) == true) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max()), '\n';
			system("cls");
			randomaichoice = rand() % 9 + 1;
		}
		invalidchoice.emplace_back(randomaichoice);
		board[randomaichoice - 1] = 'O';
		playeroneturn = true;
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

void game_AI() 
{
	while (checkwin() == false && invalidchoice.size() < 9)
	{
		//system("cls");
		printBoard();
		oneplayer();
	}
	if (checkwin() == true)
	{
		printBoard();
		int player;
		if (playeroneturn != true) {
			std::cout << "Congratulations Player one, you are the winner" << std::endl;
		}
		else if (playeroneturn == true)
		{
			std::cout << "AI is the winner" << std::endl;
		}
	}
	else if (invalidchoice.size() == 9) {
		printBoard();
		std::cout << "It's a tie!" << std::endl;
	}
	replaysystem();
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
			std::cout << "Congratulations Player one, you are the winner" << std::endl;
		}
			else if (playeroneturn == true) 
			{
			std::cout << "Congratulations Player 2, you are the winner" << std::endl;
			}
		}
	else if (invalidchoice.size() == 9) {
		printBoard();
		std::cout << "It's a tie!" << std::endl;
	}
	replaysystem();
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

	std::cout << "\n\n\n[1] Single player vs AI " << std::endl;
	std::cout << "[2] Two players " << std::endl;
	std::cout << "[0] Exit terminal" << std::endl;
	std::cout << "\nInput: ";


	int game;
	std::cin >> game;
	do{
		do{
			switch (game){
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
		} while (true);
	} while (replaygame==1);
	return 0;
}