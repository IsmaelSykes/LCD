#include "lcd_LL.h"

//------- LCD_LL at Master ---- 

lcd_LL_status_t log_command(lcd_port_t *pines,uint8_t cmd)
{
	/*printf("\r\n --- Index of Pines----\r\n");
	printf("\r RS: %d \r\n",pines->RS.index);
	printf("\r E: %d \r\n",pines->E.index);
	printf("\r P0: %d \r\n",pines->D0.index);
	printf("\r P1: %d \r\n",pines->D1.index);
	printf("\r P2: %d \r\n",pines->D2.index);
	printf("\r P3: %d \r\n",pines->D3.index);
	printf("\r P4: %d \r\n",pines->D4.index);
	printf("\r P5: %d \r\n",pines->D5.index);
	printf("\r P6: %d \r\n",pines->D6.index);
	printf("\r P7: %d \r\n",pines->D7.index);
	*/
	printf("\r\n --- States of pines----\r\n");
	printf(" %d ", pin_state(cmd,pines->D7.index));
	printf(" %d ", pin_state(cmd,pines->D6.index));
	printf(" %d ", pin_state(cmd,pines->D5.index));
	printf(" %d ", pin_state(cmd,pines->D4.index));
	printf(" %d ", pin_state(cmd,pines->D3.index));
	printf(" %d ", pin_state(cmd,pines->D2.index));
	printf(" %d ", pin_state(cmd,pines->D1.index));
	printf(" %d ", pin_state(cmd,pines->D0.index));

	return LCD_COMMAND_OK;
}


lcd_LL_status_t log_data(lcd_port_t *pines,uint8_t d)
{
	/*printf("\r\n --- Index of Pines----\r\n");
	printf("\r RS: %d \r\n",pines->RS.index);
	printf("\r E: %d \r\n",pines->E.index);
	printf("\r P0: %d \r\n",pines->D0.index);
	printf("\r P1: %d \r\n",pines->D1.index);
	printf("\r P2: %d \r\n",pines->D2.index);
	printf("\r P3: %d \r\n",pines->D3.index);
	printf("\r P4: %d \r\n",pines->D4.index);
	printf("\r P5: %d \r\n",pines->D5.index);
	printf("\r P6: %d \r\n",pines->D6.index);
	printf("\r P7: %d \r\n",pines->D7.index);
	*/
	printf("\r\n --- States of pines----\r\n");
	printf(" %d ", pin_state(d,pines->D7.index));
	printf(" %d ", pin_state(d,pines->D6.index));
	printf(" %d ", pin_state(d,pines->D5.index));
	printf(" %d ", pin_state(d,pines->D4.index));
	printf(" %d ", pin_state(d,pines->D3.index));
	printf(" %d ", pin_state(d,pines->D2.index));
	printf(" %d ", pin_state(d,pines->D1.index));
	printf(" %d ", pin_state(d,pines->D0.index));

	return LCD_DATA_OK;
}


lcd_LL_status_t write_command(lcd_port_t *pines,uint8_t cmd)
{
	HAL_GPIO_WritePin(pines->RS.port, pines->RS.pin, 0);
	//----------------------------------------------------------
	HAL_GPIO_WritePin(pines->D0.port, pines->D0.pin,pin_state(cmd,pines->D0.index));
	HAL_GPIO_WritePin(pines->D1.port, pines->D1.pin,pin_state(cmd,pines->D1.index));
	HAL_GPIO_WritePin(pines->D2.port, pines->D2.pin,pin_state(cmd,pines->D2.index));
	HAL_GPIO_WritePin(pines->D3.port, pines->D3.pin,pin_state(cmd,pines->D3.index));
	HAL_GPIO_WritePin(pines->D4.port, pines->D4.pin,pin_state(cmd,pines->D4.index));
	HAL_GPIO_WritePin(pines->D5.port, pines->D5.pin,pin_state(cmd,pines->D5.index));
	HAL_GPIO_WritePin(pines->D6.port, pines->D6.pin,pin_state(cmd,pines->D6.index));
	HAL_GPIO_WritePin(pines->D7.port, pines->D7.pin,pin_state(cmd,pines->D7.index));
	log_command(pines,cmd);
	//----------------------------------------------------------                              
	HAL_GPIO_WritePin(pines->E.port, pines->E.pin,1);
	HAL_Delay(10);
	HAL_GPIO_WritePin(pines->E.port, pines->E.pin,0);

	return LCD_COMMAND_OK;
}

lcd_LL_status_t write_data(lcd_port_t *pines,uint8_t d)
{
	HAL_GPIO_WritePin(pines->RS.port, pines->RS.pin, 1);  
	//----------------------------------------------------------
	HAL_GPIO_WritePin(pines->D0.port, pines->D0.pin,pin_state(d,pines->D0.index));
	HAL_GPIO_WritePin(pines->D1.port, pines->D1.pin,pin_state(d,pines->D1.index));
	HAL_GPIO_WritePin(pines->D2.port, pines->D2.pin,pin_state(d,pines->D2.index));
	HAL_GPIO_WritePin(pines->D3.port, pines->D3.pin,pin_state(d,pines->D3.index));
	HAL_GPIO_WritePin(pines->D4.port, pines->D4.pin,pin_state(d,pines->D4.index));
	HAL_GPIO_WritePin(pines->D5.port, pines->D5.pin,pin_state(d,pines->D5.index));
	HAL_GPIO_WritePin(pines->D6.port, pines->D6.pin,pin_state(d,pines->D6.index));
	HAL_GPIO_WritePin(pines->D7.port, pines->D7.pin,pin_state(d,pines->D7.index));
	log_data(pines,d);
	//----------------------------------------------------------                           
	HAL_GPIO_WritePin(pines->E.port, pines->E.pin,1);
	HAL_Delay(10);
	HAL_GPIO_WritePin(pines->E.port, pines->E.pin,0);

	return LCD_DATA_OK;
}