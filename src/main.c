#include <ti/getcsc.h>
#include <stdint.h>
#include <stdbool.h>
#include "hexc.h"

int main(void)
{
	init_screen();

	uint8_t key, base = 10;
	uint64_t op2; //temporary storage of second operator
	extern uint8_t is_stack_lift_enabled, overwrite;

	while (true) {

		if (boot_CheckOnPressed())
			break;

		key = os_GetCSC();

		switch (key) {
		case sk_0:
			push_digit(0, base);
			break;
		case sk_1:
			push_digit(1, base);
			break;
		case sk_2:
			push_digit(2, base);
			break;
		case sk_3:
			push_digit(3, base);
			break;
		case sk_4:
			push_digit(4, base);
			break;
		case sk_5:
			push_digit(5, base);
			break;
		case sk_6:
			push_digit(6, base);
			break;
		case sk_7:
			push_digit(7, base);
			break;
		case sk_8:
			push_digit(8, base);
			break;
		case sk_9:
			push_digit(9, base);
			break;
		case sk_Add:
			is_stack_lift_enabled = true;
			push(pop() + pop());
			is_stack_lift_enabled = true;
			break;
		case sk_Sub:
			is_stack_lift_enabled = true;
			op2 = pop();
			push(pop() - op2);
			is_stack_lift_enabled = true;
			break;
		case sk_Mul:
			is_stack_lift_enabled = true;
			push(pop() * pop());
			is_stack_lift_enabled = true;
			break;
		case sk_Div:
			op2 = pop();
			if (op2 == 0) {
				;
			} else {
				is_stack_lift_enabled = true;
				push(pop() / op2);
			}
			is_stack_lift_enabled = true;
			break;
		case sk_Clear:
			is_stack_lift_enabled = false;
			push(0);
			break;
		case sk_Enter:
			lift_stack();
			is_stack_lift_enabled = false;
			overwrite = true;
			break;
		default:
			/* dont update display if no keys are pressed */
			goto skip_display_update;
		}

		/* display the contents of register x */
		display_int(get_reg_x(), 'd');
skip_display_update:
		;
	}

	end_screen();
	return 0;
}
