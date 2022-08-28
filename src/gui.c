#include <graphx.h>
#include <stdio.h>
#include "hexc.h"

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

	gfx_SetTextXY(16, 18);

	gfx_PrintUInt(123, 4);
	gfx_PrintString("  ");
	gfx_PrintUInt(1, 4);
	gfx_PrintString("  ");
	gfx_PrintString("89AB");
	gfx_PrintString("  ");
	gfx_PrintString("CDEF");

	//int yp = gfx_GetTextX();
	//gfx_SetTextXY(16, 50);
	//gfx_PrintUInt(yp, 8);

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
		break;
	}

	while (str[i] != 0)
		i++;

	int start_pixel = (DISPLAY_X + DISPLAY_LENGTH) - DIGIT_WIDTH_PX * i ;
	gfx_SetTextXY(start_pixel, 18);
	clear_disp();
	gfx_PrintString(str);

	return 0;
}

int end_screen(void)
{
	gfx_End();
	return 0;
}
