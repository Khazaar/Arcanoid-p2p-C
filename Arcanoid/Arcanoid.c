#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "Arcanoid_types.h"
#include "Inits.h"
#include "Puts.h"
#include "Motions.h"
#include "Display.h"

void frendshipWis() {
	printf("Frendship Wins!!");
}

int main() {
	TRacket racketA;
	TRacket racketB;
	TBall ball;
	int pass;

	int totalHits = 0;
	int* p_level;
	int level = 1;
	char field[25][65 + 1];

	char c;
	BOOL isRun = FALSE;
	BOOL isWon = FALSE;
	pass = 0;

	//p_level = &level;
	init(&level, field);
	initRacketA(&racketA);
	initRacketB(&racketB);
	initBall(&level, &ball);
	do
	{
		if (isRun) runBall(field, &ball, &totalHits);

		if (ball.iy == 0) {
			racketA.winRate++;
			isRun = FALSE;
			initBall(&level, &ball);
			totalHits = 0;
			pass++;
		}
		if (ball.iy == heigth) {
			racketB.winRate++;
			isRun = FALSE;
			initBall(&level, &ball);
			totalHits = 0;
			pass++;
		}
		init(&level, field);
		setCursor(0, 0);
		putRacketA(field, racketA);
		putRacketB(field, racketB);
		putBall(field, ball);
		show(&level, field, totalHits, racketA, racketB);

		if (GetKeyState('A') < 0) moveRacketA(racketA.x - 1, &racketA);
		if (GetKeyState('D') < 0) moveRacketA(racketA.x + 1, &racketA);

		if (GetKeyState('J') < 0) moveRacketB(racketB.x - 1, &racketB);
		if (GetKeyState('L') < 0) moveRacketB(racketB.x + 1, &racketB);

		if (GetKeyState('R') < 0) {
			isRun = TRUE;
		}
		Sleep(1);
		if (isRun == FALSE) {
			if ((pass % 2) == 0) {
				moveBall(racketA.y - 2, racketA.x + racketA.w / 2, &ball);
			}
			else {
				moveBall(racketB.y + 2, racketB.x + racketB.w / 2, &ball);
				ball.alpha = -ball.alpha;
			}
		}

		//if ((racketA.winRate > 5) || (racketB.winRate > 5)) {
		if (totalHits > 12) {
			level = level + 1;
			isRun = FALSE;
			racketA.winRate = 0;
			racketB.winRate = 0;
			totalHits = 0;
		}

		if (level == 4) {
			frendshipWis();
			Sleep(10000);
			isWon = TRUE;

		}
	} while ((GetKeyState('Q') >= 0) & (!isWon));
}

