#include <8051.h>

interrupt void interrupt1() {
	if(P00 == 0)
		P00 = 1;
	else
		P00 = 0;
	
}

void main()
{
	P0 = P1 = P2 = P3 = 0;
	
	IE_BITS.B0 = 1;
	IE_BITS.B7 = 1;
	TCON_BITS.B0 = 1;
	
	while (1){
		P36 = 1;
		P36 = 0;
		while (P37 == 1);
		P2 = P1;
	}
}
