#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>



void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
bool valid(int, int);

int board[3][3];
const char player = 'X';
const char computer = 'O';
int main() 
{
	char winner =  ' ';
	resetBoard();
	while (winner == ' ' && checkFreeSpaces()!=0) 
	{
		printBoard(); 
		playerMove();
		winner = checkWinner();
		if (winner != ' ')break;
		computerMove();
		winner=checkWinner();
	}
	if (winner == ' ')
	{
		printf("DRAW");

	}
	if (winner == 'X') printf("YOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	if (winner == 'O') printf("YOU LOSE:(((");




	return 0;
}
void resetBoard() 
// clear the board

{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
	}

}
void printBoard()
//print the curent board
{

		printf("\n %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
		printf("---|---|--- \n ");
		printf("%c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
		printf("---|---|--- \n ");
		printf("%c | %c | %c \n", board[2][0], board[2][1], board[2][2]);



		

}
int checkFreeSpaces()
// verify if there empty spaces in the board
// return the number of empty splaces on the board
{
	int free_spaces = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == ' ')
				free_spaces++;
	return free_spaces;

}
void playerMove()
/*the player move
the numbers itroduced by by the player must be between (1-3)
else print:non-existent position
*/ 

{
	int row, column;
	bool wrong = false;
	do {
		 wrong = false;
		printf("\ninsert row(1-3):");
		scanf("%d", &row);

		printf("\ninsert column(1-3):");
		scanf("%d", &column);
		row--;
		column--;
		
		if (valid(row, column))
		{
			if (board[row][column] != ' ')
			{
				printf("\nthis space is not empty\n try again:");
				wrong = true;
			}
			else {

				board[row][column] = 'X';
				break;
			}
		}
		else {
			printf("\nnon-existent position");
			wrong = true;


		}

	} while (wrong==true);



}
//simulate the computer move 
void computerMove()
{
	srand(time(0));
	int ok = 0;
	if (checkFreeSpaces()>0)
	{
		while (ok == 0)
		{
			ok = 1;
			int row = rand() % 3;
			int column = rand() % 3;
			if (board[row][column] == ' ')
				board[row][column] = 'O';
			else ok = 0;
		}

	}

}
//verify is the game has a winner
char checkWinner()
{
	for (int i = 0; i < 3; i++)
	{
		
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0]!=' ')
			return board[i][0];
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i]!=' ')
			return board[0][i];
	}
	
	if (board[0][0] == board[1][1] && board[2][2] == board[0][0] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[2][0] == board[0][2] && board[0][2] != ' ')
		return board[0][2];
	return ' ';



}
bool valid(int row, int column)
// verify if a position is valid
{
	if (row <3 && row>-1 && column <3 && column>-1)
		return true;
	return false;


}