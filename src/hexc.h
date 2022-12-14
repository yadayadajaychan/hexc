#ifndef HEXC_H
#define HEXC_H

#define DISPLAY_X 10
#define DISPLAY_Y 10
#define DISPLAY_LENGTH 300
#define DISPLAY_HEIGHT 50

#define BASE_INDICATOR_X (DISPLAY_X + DISPLAY_LENGTH - DISPLAY_HEIGHT)
#define BASE_INDICATOR_Y (DISPLAY_Y + DISPLAY_HEIGHT - 1)

#define DIGIT_WIDTH_SCALE 2
#define DIGIT_HEIGHT_SCALE 5
#define DIGIT_WIDTH_PX 20 //approximate

#define WHITE 255
#define BLACK 0

/* gui.c */
int init_screen(void);
int clear_disp(void);
int clear_base(void);
int display_int(int num, char mode);
int end_screen(void);

/* stack.c */
void lift_stack(void);
void push(uint64_t num);
void push_digit(uint8_t num, uint8_t base);
uint64_t pop(void);
uint64_t get_reg_x(void);
void set_last_x(void);
void push_last_x(void);

#endif /* HEXC_H */
