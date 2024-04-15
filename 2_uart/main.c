#include <stdint.h>
#include "uart.h"
#include "gpio.h"


void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);

	// Fill inn the configuration for the remaining buttons 
}

int ubit_button_press_a(){
	return (!(GPIO->IN & (1 << 13)));
}

int ubit_button_press_b(){
	return (!(GPIO->IN & (1 << 14)));
}



int main(){
	// Configure LED Matrix

	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
		GPIO->OUTSET = (1 << i);
	}

	// Configure buttons -> see button_init()


	//int sleep = 0;
	while(1){
		uart_send('A');
		if (ubit_button_press_a()){

			uart_send('A');
		 }

		if (ubit_button_press_b()){

			uart_send('B');
		 }
		 if (ubit_button_press_a()){

			GPIO->OUTSET = (1 << 18);
		 }

		 if (!(GPIO->IN & (1 << 13))){

			GPIO->OUTCLR = (1 << 18);
		 }

		//sleep = 10000;
		//while(--sleep); // Delay
	}
	return 0;
}
