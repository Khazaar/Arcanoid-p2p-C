#include "Arcanoid_types.h"

void putRacketA(char(*field)[66], TRacket racketA) {
	for (int i = 0; i < racketA.w; i++)
	{
		field[heigth - 1][racketA.x + i] = '=';
	}
}

void putRacketB(char(*field)[66], TRacket racketB) {
	for (int i = 0; i < racketB.w; i++)
	{
		field[1][racketB.x + i] = '=';
	}
}

void putBall(char(*field)[66], TBall ball) {
	field[ball.iy][ball.ix] = 'o';
}