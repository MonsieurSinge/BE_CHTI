#include "DriverJeuLaser.h"

extern short int LeSignal[64]; 

int x;
int tab[64];
short int dma_buf[64];

void callbackSystick();

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();

// Tck = 0,0138�s
// il nous faut 320kHz = 0,000003125s = 3,125�s
// 3,125 / 0,0138 = 227
Systick_Period_ff(360000);
Systick_Prio_IT( 0, callbackSystick );
SysTick_On;
SysTick_Enable_IT;
	
Init_TimingADC_ActiveADC_ff( ADC1, 72 );
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	

//============================================================================	
	
while	(1)
	{
		/*
		for (int i = 0; i < 64; i++) {
			tab[i] = DFT_ModuleAuCarre(dma_buf, i);
		}*/
		//x = DFT_ModuleAuCarre(dma_buf, 5);

		int i = 0;
	}
}

void callbackSystick() {
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	for (int i = 0; i < 64; i++) {
			tab[i] = DFT_ModuleAuCarre(dma_buf, i);
	}
}