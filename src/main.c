#include <ti/getcsc.h>
#include "hexc.h"

int main(void)
{
	init_screen();

	while (!os_GetCSC());

	///clear_disp();
	///clear_base();
	///gfx_SetTextXY(16, 18);
	///gfx_PrintUInt(123, 4);
	display_int(10000, 'h');

	while (!os_GetCSC());
	end_screen();
	return 0;
}
