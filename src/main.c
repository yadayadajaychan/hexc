#include <ti/getcsc.h>
#include "hexc.h"

int main(void)
{
	init_screen();

	while (!os_GetCSC());

	///gfx_SetTextXY(16, 18);
	display_int(10000, 'h');

	while (!os_GetCSC());
	end_screen();
	return 0;
}
