#define NOMINMAX 
#include <iostream>		// standard library header
#include <conio.h>		// For _getch();
#include <cstdlib>		// for rand() and srand()
#include <ctime>		// for time
#include <vector>		// for vectors
#include <string>
//global
std::vector <int> invalidchoice;
std::vector	<char> board = { '1','2','3','4','5','6','7','8','9' };  //Vector board instead of Array as it was asked to practice more of vector
bool playeroneturn = true;
int replaygame{ 1 };
bool fixproblem = true;
int integer;

//local
void clearboard() {				// Clears the board of 'X' and 'O' if the player want to restart a game. 
	invalidchoice.clear();
	for (int i = 1; i <= 9; i++)
	{
		char replace = '0' + i;
		board[i - 1] = replace;
	}
}

void replaysystem() {			// Lets the player be able to play the same match again or if they want to exit the console. 
	std::cout << "Would you like to play again?\nReplay same game [1]\nExit game [0]" << std::endl;
	do{
		std::cin >> replaygame;
		switch (replaygame){
		case 1:
			clearboard();
			playeroneturn = true;	/* made that X starts the game. 
									If player want to remove that option 
									and made it so that the game interchange, 
									this line can be commented out*/

			fixproblem = false;		/* Made the "fixproblem" to solve 
									how the player could decide to 
									start a new round without it bugging*/
			break;
		case 0:
			exit(1);				// Tried to make it go to main menu and select a new option, 
									//but instead opted to make it exit game alltogether. 
			break;
		default:
			std::cout << "\nPlease select a number [0-1]. ";
			break;					//force the player or ai to select a valid integer
		}
	} while (fixproblem == true);	//For the Play again option to work.
}

int getinputfromuser (){
	std::cin >> integer;
	while (std::cin.fail() || integer <= 0 || integer > 9 || std::count(invalidchoice.begin(), invalidchoice.end(), integer)) { /* this is to make sure the number 
																																doesn't get chosen again*/
		std::cout << "Error: not a valid number.\n";
		std::cin >> integer;
	}  
	invalidchoice.emplace_back(integer);
	return integer;
}

void oneplayer()
{
	if (playeroneturn == true){
		std::cout << "Player's [X] turn: ";
		board[getinputfromuser() - 1] = 'X';
		playeroneturn = false;
	}
	else if (playeroneturn == false) {
		std::srand(static_cast<unsigned int>(time(nullptr))); //Ai player choses a random number, rather being advanced. 
		int randomaichoice = rand() % 9 + 1;
		while (std::cin.fail() || randomaichoice > 9 || randomaichoice <= 0 || std::count(invalidchoice.begin(), invalidchoice.end(), randomaichoice)) {
			randomaichoice = rand() % 9 + 1;
		}
		invalidchoice.emplace_back(randomaichoice);
		board[randomaichoice - 1] = 'O';
		playeroneturn = true;
	}
}

void twoplayer() //two players
{
	if (playeroneturn == true){ //player one
		std::cout << "Player 1's [X] turn: ";
		board[getinputfromuser() - 1] = 'X';
		playeroneturn = false;
	}
	else if (playeroneturn == false) // player two
	{
		std::cout << "Player 2's [O] turn: ";
		board[getinputfromuser() - 1] = 'O';
		playeroneturn = true;
	} 
}

bool checkwin()  //check win to see if the lines diagonally, vertically, or horizontally is correct and after eachother. If true, then win. Else, it's a tie.
{
	if (board[0] == board[1] && board[1] == board[2]) {			//Horizontal win conditions begin
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5]) {
		return true;
	}
	else if (board[6] == board[7] && board[7] == board[8]) {	//horizontal win conditions end
		return true;
	}
	else if (board[0] == board[3] && board[3] == board[6]) {	//vertical win conditions begin
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7]) {
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8]) {	//vertical win cnditions end
		return true;
	}
	else if (board[0] == board[4] && board[4] == board[8]) {	//diagonal win conditions begin
		return true;
	}
	else if (board[2] == board[4] && board[4] == board[6]) {	//diagonal win conditions end
		return true;
	}
	else{
		return false; //Return false make it so that it turn to a draw by invalidchoice.size() == 9 
	}
}

void printBoard() {		//prints and updates the board to see a new character in the board.at()
	system("cls");
	for (int i = 0; i < board.size(); i+=3){
		std::cout << " " << board.at(i) << " | " << board.at(i + 1) << " | " << board.at(i + 2) << " " << std::endl;
		if (i < 6)
			std::cout << "---|---|---" << std::endl;
	  }
	  std::cout << std::endl;
}

void game_AI() {	//game against AI
	while (checkwin() == false && invalidchoice.size() < 9){
		printBoard();	//prints out updated board
		oneplayer();	//gets game conditions from oneplayer
	}
	if (checkwin() == true){	//if checkwin is true, then a winner is announced
		printBoard();
		if (playeroneturn != true) {
			std::cout << "Congratulations Player one, you are the winner" << std::endl;
		}
		else if (playeroneturn == true){
			std::cout << "AI is the winner" << std::endl;
		}
	}
	else if (invalidchoice.size() == 9) {	//if checkwin is false, this pops up
		printBoard();
		std::cout << "It's a tie!" << std::endl;
	}
	replaysystem();							//prints out the replay system to see if you want to restart or exit the game
}

void game_2_players() {						// two player game with humans.
	while (checkwin() == false && invalidchoice.size() < 9 ){
		printBoard();						//prints out updated board
		twoplayer();						//gets game condition from twoplaer
	}
	if (checkwin() == true) {				//if checkwin is true, then a winner is announced
		printBoard();
		if (playeroneturn != true) {
			std::cout << "Congratulations Player one, you are the winner" << std::endl;
		}
			else if (playeroneturn == true) {
			std::cout << "Congratulations Player 2, you are the winner" << std::endl;
			}
		}
	else if (invalidchoice.size() == 9) {	//if checkwin is false, this pops up
		printBoard();
		std::cout << "It's a tie!" << std::endl;
	}
	replaysystem();							//prints out the replay system to see if you want to restart or exit the game
}

int main() {
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
	std::cin >> game;		//game select
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
		} while (true);			//to select the option
	} while (replaygame==1);	//to replay the same game mode and looping this
	return 0;
}