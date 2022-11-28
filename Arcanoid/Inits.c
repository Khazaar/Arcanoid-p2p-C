#include "Arcanoid_types.h"
void init(int* level, char(*field)[66]) {
	int block_y1, block_y2, block_y3, block_x11, block_x12, block_x21, block_x22, block_x3;
	switch (*level)
	{
	case 1:
		field[0][0] = '#';
		field[0][width - 1] = '#';
		field[0][width] = '\0';

		for (int i = 1; (i < width - 1); i++)
		{
			field[0][i] = ' ';
		}
		for (int i = 1; (i < heigth); i++)
		{
			strncpy(field[i], field[0], width + 1);
		}
		break;
	case 2:
		field[0][0] = '#';
		field[0][width - 1] = '#';
		field[0][width] = '\0';

		for (int i = 1; (i < width - 1); i++)
		{
			field[0][i] = ' ';
		}
		for (int i = 1; (i < heigth); i++)
		{
			strncpy(field[i], field[0], width + 1);
		}
		block_x11 = (int)width * 0.3;
		for (int j = block_x11; (j < width - block_x11); j++)
		{
			block_y1 = (int)heigth * 0.5;

			field[block_y1][j] = '~';
		}
		break;

	case 3:
		field[0][0] = '#';
		field[0][width - 1] = '#';
		field[0][width] = '\0';

		for (int i = 1; (i < width - 1); i++)
		{
			field[0][i] = ' ';
		}
		for (int i = 1; (i < heigth); i++)
		{
			strncpy(field[i], field[0], width + 1);
		}
		block_y1 = (int)heigth * 0.333;
		block_y2 = (int)heigth * 0.666;
		block_x11 = (int)width * 0.2;
		block_x21 = (int)width * 0.85;
		block_x12 = (int)width * 0.15;
		block_x22 = (int)width * 0.8;

		for (int j = 0; (j < block_x11); j++)
		{
			field[block_y1][j] = '~';
		}
		for (int j = block_x21; (j < width); j++)
		{
			field[block_y1][j] = '~';
		}

		for (int j = 0; (j < block_x12); j++)
		{
			field[block_y2][j] = '~';
		}
		for (int j = block_x22; (j < width); j++)
		{
			field[block_y2][j] = '~';
		}

	default:
		break;
	}
}

void initRacketA(TRacket* racketA) {
	(*racketA).w = 12;
	(*racketA).x = (-(*racketA).w + width) / 2;
	(*racketA).y = heigth;
	(*racketA).winRate = 0;
}

void initRacketB(TRacket* racketB) {
	(*racketB).w = 12;
	(*racketB).x = (-(*racketB).w + width) / 2;
	(*racketB).y = 0;
	(*racketB).winRate = 0;
}

void initBall(int* level, TBall* ball) {
	(*ball).x = 2;
	(*ball).y = 2;
	(*ball).ix = (int)round((*ball).x);
	(*ball).iy = (int)round((*ball).y);
	(*ball).alpha = -pi / 2 * 0.7;
	(*ball).vel = (0.7 + *level * 0.2) * 0.5;
}