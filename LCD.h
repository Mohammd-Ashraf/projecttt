#ifndef LCD_H_
#define LCD_H_

void LCD_Int(void);
static void Pulse_func(void);
void LCD_Send_Command(char command);
void LCD_Send_character(char character);
void LCD_Send_string(char *data);
void LCD_clearScreen(void);
void cursor_move(char row , char column);

#endif
