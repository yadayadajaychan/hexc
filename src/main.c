#include <ti/getcsc.h>
#include "hexc.h"

int main(void)
{
	init_screen();

	uint8_t key;
	uint64_t op2; //temporary storage of second operator
	extern int is_stack_lift_enabled;

	while (true) {

		if (boot_CheckOnPressed())
			break;

		key = os_GetCSC();

		switch (key) {
		case sk_0:
			push(0);
			break;
		case sk_1:
			push(1);
			break;
		case sk_2:
			push(2);
			break;
		case sk_3:
			push(3);
			break;
		case sk_4:
			push(4);
			break;
		case sk_5:
			push(5);
			break;
		case sk_6:
			push(6);
			break;
		case sk_7:
			push(7);
			break;
		case sk_8:
			push(8);
			break;
		case sk_9:
			push(9);
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
		case sk_Enter:
			lift_stack();
			is_stack_lift_enabled = false;
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
