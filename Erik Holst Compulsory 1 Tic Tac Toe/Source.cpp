#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <Windows.h>



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



	return 0;
}