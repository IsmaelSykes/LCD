#ifndef INC_LCD_LL_H_
#define INC_LCD_LL_H_
// ------- LCD_LL at Master ---------
// ------- libraries --------
#include <stdio.h>
#include <stdint.h>

//-------  target  ----------
#include "stm32g0xx_hal.h"

//---------- Get state of pin from data 
#define pin_state(_reg,_pin)    ((_reg&(1<<_pin))>>_pin)

//-------- PORTS and PINES--------------
struct port_pin_t
{
	GPIO_TypeDef      *port; // port_register 
	uint16_t          pin;   // pin_register
	uint16_t          index; // #pin
};

// LCD interface
typedef struct
{
	struct port_pin_t RS;   //Register select pin
	struct port_pin_t RW;   //Read/Write pin
	struct port_pin_t E;    //Enable pin
	struct port_pin_t D0;   //D0 pin
	struct port_pin_t D1;   //D1 pin
	struct port_pin_t D2;   //D2 pin
	struct port_pin_t D3;   //D3 pin
	struct port_pin_t D4;   //D4 pin
	struct port_pin_t D5;   //D5 pin
	struct port_pin_t D6;   //D6 pin
	struct port_pin_t D7;   //D7 pin

}lcd_port_t;

typedef enum {

	LCD_COMMAND_OK,
	LCD_COMMAND_ERR,
	LCD_DATA_OK,
	LCD_DATA_ERR,

}lcd_LL_status_t;

lcd_LL_status_t log_command(lcd_port_t *pines,uint8_t cmd);
lcd_LL_status_t log_data(lcd_port_t *pines,uint8_t d);
lcd_LL_status_t write_command(lcd_port_t *pines,uint8_t cmd);
lcd_LL_status_t write_data(lcd_port_t *pines,uint8_t d);

#endif /* INC_LCD_LL_H_ */