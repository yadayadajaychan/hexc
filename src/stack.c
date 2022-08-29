#include <stdint.h>
#include "hexc.h"

/* whether or not the stack should be lifted when values are pushed */
int is_stack_lift = FALSE;

static uint64_t stack[4] = {0};
static uint64_t last_x = 0;

void lift_stack(void)
{
	stack[3] = stack[2];
	stack[2] = stack[1];
	stack[1] = stack[0];
}

void push(uint64_t num)
{
	if (is_stack_lift) {
		stack[3] = stack[2];
		stack[2] = stack[1];
		stack[1] = stack[0];
	}
	stack[0] = num;
}

uint64_t pop(void)
{
	static uint64_t reg_x;
	reg_x = stack[0];

	/* drop the stack */
	stack[0] = stack[1];
	stack[1] = stack[2];
	stack[2] = stack[3];

	return reg_x;
}

/* get the value of register x without dropping the stack */
uint64_t get_reg_x(void)
{
	return stack[0];
}

void set_last_x(void)
{
	last_x = stack[0];
}

void push_last_x(void)
{
	is_stack_lift = TRUE;
	push(last_x);
}
