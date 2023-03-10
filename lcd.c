#include "lcd.h"
//------------ LCD at develop -------

/*This Function initilicer the LCD display*/
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


/*This Function clear the display and puts the cursor in position 0,0*/
lcd_status_t clear(lcd_port_t *pines)
{
	write_command(pines,LCD_DISPLAY_CURSOR_HOME);
	write_command(pines,LCD_CLEAR_DISPLAY);

	printf("\r\n  --- LCD Clear Display ----\r\n");
	return LCD_CLEAR_OK;
}

/*This Function pints an message into LCD display*/
lcd_status_t message(lcd_port_t *pines,char *message, size_t length)
{
	for(int i =0; i< length-1; i++)
		write_data(pines,*(message++));

	return LCD_MESSAGE_OK;
}

/*This Function get a digits form float numbers*/
lcd_status_t get_number(char *string,size_t len, char *fmt, ...)
{
   va_list arg_ptr;
   va_start(arg_ptr, fmt);
   vsnprintf(string, len, fmt, arg_ptr);
   va_end(arg_ptr);

   return LCD_INT2STR_OK;
}

/*This function move the cursor, puts it x and y coordinates*/
lcd_status_t place(lcd_port_t *pines,size_t raw, size_t column)
{ 
	if(raw == 1)
	{
		write_command(pines,(0x80 | column));
	}
	if(raw == 2)
	{
		write_command(pines,(0xC0 | column));
	}

	return LCD_PLACEMENT_OK;
}