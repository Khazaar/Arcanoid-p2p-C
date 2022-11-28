#include "Arcanoid_types.h"
#include <math.h>

void moveBall(float y, float x, TBall* ball) {
	(*ball).x = x;
	(*ball).y = y;
	(*ball).ix = (int)round((*ball).x);
	(*ball).iy = (int)round((*ball).y);

}

void runBall(char(*field)[66], TBall* ball, int* totalHits) {
	TBall ball0 = *ball;
	moveBall((*ball).y + sin((*ball).alpha) * (*ball).vel * 0.55, (*ball).x + cos((*ball).alpha) * (*ball).vel, ball);

	if (field[(*ball).iy][(*ball).ix] == '#') {
		(*ball) = ball0;
		(*ball).alpha = pi - (*ball).alpha;
		Beep(2000, 5);

	}

	if ((field[(*ball).iy][(*ball).ix] == '=')) {
		(*ball) = ball0;
		//ball.alpha = -pi / 2 - 2 * ball.alpha;
		(*ball).alpha = -(*ball).alpha;
		(*totalHits)++;
		Beep(1000, 5);
	}

	if ((field[(*ball).iy][(*ball).ix] == '~')) {
		if ((field[(*ball).iy][(*ball).ix - 1] != ' ') && (field[(*ball).iy][(*ball).ix + 1] != ' ')) {
			(*ball) = ball0;
			//ball.alpha = -pi / 2 - 2 * ball.alpha;
			(*ball).alpha = -(*ball).alpha;
			Beep(3000, 5);
		}
	}
}

void moveRacketA(int x, TRacket* racketA) {
	(*racketA).x = x;
	if (x < 1) (*racketA).x = 1;
	if ((*racketA).x + (*racketA).w > width) (*racketA).x = width - (*racketA).w - 1;
}

void moveRacketB(int x, TRacket* racketB) {
	(*racketB).x = x;
	if (x < 1) (*racketB).x = 1;
	if ((*racketB).x + (*racketB).w > width) (*racketB).x = width - (*racketB).w - 1;
}