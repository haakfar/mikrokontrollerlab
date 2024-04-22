#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"


void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);

	// Fill inn the configuration for the remaining buttons 
}


int main()
{


    button_init();

    GPIOTE->CONFIG[0] = 1 | (13 << 8) | (2 << 16);

    GPIOTE->CONFIG[1] = 3 | (17 << 8) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[2] = 3 | (18 << 8) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[3] = 3 | (19 << 8) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[4] = 3 | (20 << 8) | (3 << 16) | (0 << 20);


    PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]);
    PPI->CHENSET = 1;

    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[2]);
    PPI->CHENSET = (1 << 1);

    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[3]);
    PPI->CHENSET = (1 << 2);

    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[4]);
    PPI->CHENSET = (1 << 3);






int sleep = 0;
while (1){

    sleep = 10000;
    while(--sleep); // Delay



}







}