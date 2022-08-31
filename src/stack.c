#include <stdint.h>
#include <stdbool.h>
#include "hexc.h"

/* whether or not the stack should be lifted when values are pushed */
uint8_t is_stack_lift_enabled = false;
/* whether or not the current value on the stack should be overwritten */
uint8_t overwrite = true;

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
	if (is_stack_lift_enabled) {
		stack[3] = stack[2];
		stack[2] = stack[1];
		stack[1] = stack[0];

		is_stack_lift_enabled = false;
	}
	stack[0] = num;
}

void push_digit(uint8_t num, uint8_t base)
{
	extern uint8_t overwrite;

	if (is_stack_lift_enabled) {
		push(num);
	} else if (overwrite) {
		push(num);
		overwrite = false;
	} else {
		push(get_reg_x() * base + num);
	}
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
	is_stack_lift_enabled = true;
	push(last_x);
}
