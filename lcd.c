#include "lcd.h"

lcd_status_t lcd_init(lcd_port_t *pines)
{
	write_command(pines,LCD_FUNTION_SET);
	write_command(pines,LCD_DISPLAY_CURSOR_SET);
	write_command(pines,LCD_CHARACTER_ENTRY_MODE);
	write_command(pines,LCD_DISPLAY_CURSOR_HOME);
	write_command(pines,LCD_DISPLAY_CURSOR_SHIFT);
	write_command(pines,LCD_CLEAR_DISPLAY);

	printf("\r\n  --- LCD Init----\r\n");
	return LCD_INIT_OK;
}

lcd_status_t clear(lcd_port_t *pines)
{
	write_command(pines,LCD_DISPLAY_CURSOR_HOME);
	write_command(pines,LCD_CLEAR_DISPLAY);

	printf("\r\n  --- LCD Clear Display ----\r\n");
	return LCD_CLEAR_OK;
}