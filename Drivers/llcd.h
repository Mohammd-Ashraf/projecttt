




void LCD_INIT(void);
void lcd_command(unsigned char cmd);
void send_char(unsigned char data);
void send_String(unsigned char *data);
void LCD_Move_Cursor(unsigned char row, unsigned char col);
void LCD_COUNT_DOWN(unsigned char timer);
void LCD_HOLD(unsigned char hold, unsigned char time);
