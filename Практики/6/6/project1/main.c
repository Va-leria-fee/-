#include <8051.h>

void tput(unsigned char c1) {
	SBUF=c1; 
	while(TI == 0);
	TL0 = 0x0;
	TH0 = 0x0;
	
	while(TF0 != 0);
	TF0 = 0;
	TI=0;
}

void main() {
	char z;
	int i;
	
	unsigned char src[]={'a','b','c'};

	TMOD_BITS.B0 = 0;
	TMOD_BITS.B1 = 1;
	SM2 = 1;
	

	TL0 = 0x0;
	TH0 = 0xFF;
	TR0 = 1;

	PCON = 0x0;
	SCON = 1;
	i = 0;
	while (1) {
		i++;
		tput ('8');
	}
	for(i=0; i<3; i++)
	{
	ACC=src[i]; 
	
	
	tput (src[i]);
	}
	while(1){} 
}
