

#include "DriverJeuLaser.h"

extern short int LeSignal[64]; 

int tab[64];

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
	

//============================================================================	
	
while	(1)
	{
		for (int i = 0; i < 64; i++) {
			tab[i] = DFT_ModuleAuCarre(LeSignal, i);
		}
		
		int i = 0;
	}
}

