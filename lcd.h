#ifndef INC_LCD_H_
#define INC_LCD_H_
//------ LCD at Master -----------------
#include "lcd_LL.h"
#include <stdarg.h>

// Function set: 8 bit, 2 line mode, and 5x7 formant
#define LCD_FUNTION_SET           (0x38)

// Display and Cursor: display off, underline on, and blink off 
#define LCD_DISPLAY_CURSOR_SET    (0x0C)

// Character enty mode: increment, display shift on 
#define LCD_CHARACTER_ENTRY_MODE  (0x06)
// Display and Cursor home
#define LCD_DISPLAY_CURSOR_HOME   (0x02)
// Clear Display
#define LCD_CLEAR_DISPLAY         (0x01)
// Display/Cursor shift: display shift off, shift left on  
#define LCD_DISPLAY_CURSOR_SHIFT  (0x10)

typedef enum {

	LCD_CLEAR_OK,
	LCD_CLEAR_ERR,
	LCD_ERR_INIT,
	LCD_INIT_OK,
	LCD_MESSAGE_OK,
	LCD_MESSAGE_ERR,
	LCD_PLACEMENT_OK,
	LCD_PLACEMENT_ERR,
	LCD_INT2STR_OK,
	LCD_INT2STR_ERR,
}lcd_status_t;

lcd_status_t lcd_init(lcd_port_t *pines);
lcd_status_t clear(lcd_port_t *pines);
lcd_status_t message(lcd_port_t *pines,char *buff, size_t length);
lcd_status_t get_number(char *string,size_t len, char *fmt, ...);
lcd_status_t place(lcd_port_t *pines,size_t raw, size_t column);
#endif /* INC_LCD_H_ */