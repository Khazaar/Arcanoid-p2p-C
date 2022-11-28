#include <Windows.h>
#include "Arcanoid_types.h"

void setCursor(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void show(int* level, char(*field)[66], int totalHits, TRacket racketA, TRacket racketB) {
	for (int i = 0; (i < heigth); i++)
	{
		printf("%s", field[i]);
		if ((i != 3) && (i != 4) && (i != 20) && (i != 21) && (i != 22) && (i != 5) && (i != 6) && (i != 8)) printf("\n");
		if (i == 3)  printf("     Player A score:			%2d\n", racketA.winRate);
		if (i == 4)  printf("     Player B score:			%2d\n", racketB.winRate);
		if (i == 5)  printf("     Total hits:			%2d\n", totalHits);
		if (i == 6)  printf("     Level:				%2d\n", *level);
		if (i == 8)  printf("     You will move to next level after 12 total hits\n");
		if (i == 20) printf("     Press R to run game		\n");
		if (i == 21) printf("     Press A and D to move player A\n");
		if (i == 22) printf("     Press J and L to move player B\n");
	}
}