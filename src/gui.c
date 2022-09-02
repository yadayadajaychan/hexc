#include <graphx.h>
#include <stdio.h>
#include "hexc.h"

static const uint16_t digit_x_position[16] = {
	286,
	268,
	250,
	232,
	214,
	196,
	178,
	160,
	142,
	124,
	106,
	88,
	70,
	52,
	34,
	16
};

int init_screen(void)
{
	gfx_Begin();
	gfx_FillScreen(WHITE);

	/* create display rectangle */
	gfx_SetColor(BLACK);
	gfx_Rectangle_NoClip(DISPLAY_X, DISPLAY_Y, DISPLAY_LENGTH,
							DISPLAY_HEIGHT);
	/* create base indicator box */
	gfx_Rectangle_NoClip(BASE_INDICATOR_X, BASE_INDICATOR_Y,
					DISPLAY_HEIGHT, DISPLAY_HEIGHT);
	/* set digit scale */
	gfx_SetTextScale(DIGIT_WIDTH_SCALE, DIGIT_HEIGHT_SCALE);

	display_int(0, 'h');

	return 0;
}

int clear_disp(void)
{
	gfx_SetColor(WHITE);
	gfx_FillRectangle_NoClip(DISPLAY_X + 1, DISPLAY_Y + 1,
					DISPLAY_LENGTH - 2, DISPLAY_HEIGHT - 2);
	return 0;
}

int clear_base(void)
{
	gfx_SetColor(WHITE);
	gfx_FillRectangle_NoClip(BASE_INDICATOR_X + 1, BASE_INDICATOR_Y + 1,
					DISPLAY_HEIGHT - 2, DISPLAY_HEIGHT - 2);
	return 0;
}

int display_int(int num, char mode)
{
	char str[17] = {0}; //the display can hold 16 digits
	int i = 0;

	switch (mode) {
	case 'd':
		sprintf(str, "%u", num);
		break;
	case 'b':
		sprintf(str, "%u", num);
		break;
	case 'o':
		sprintf(str, "%o", num);
		break;
	case 'h':
		sprintf(str, "%x", num);
		break;
	default:
		return 1;
	}

	while (str[i] != 0)
		i++;
	i--;

	/* j is the digit index and i is the array index */
	clear_disp();
	for (int j = 0; j <= i; j++) {
		gfx_SetTextXY(digit_x_position[j], 18);
		gfx_PrintChar(str[i - j]);
	}

	return 0;
}

int end_screen(void)
{
	gfx_End();
	return 0;
}
