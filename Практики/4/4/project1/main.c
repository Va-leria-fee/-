#include <8051.h>

void light (int x) {
	int i;
	for (i = 0; i < x * 10; i++) {
	TL0 = 0x0;
	TH0 = 0x0;
	TR0 = 1;
	while (TF0 != 0);
	TR0 = 0;
	TF0 = 0;
	}
}

void main()
{	
	int i;
	TMOD = 0x01;
	P1 = 0;

	P10 = 1;
	P17 = 1;
	light (1);	
	P10 = 0;
	P17 = 0;
	
	P11 = 1;
	P16 = 1;
	light (2);
	P11 = 0;
	P16 = 0;

	P12 = 1;
	P15 = 1;
	light (3);
	P12 = 0;
	P15 = 0;

	P13 = 1;
	P14 = 1;
	light (4);
	P13 = 0;
	P14 = 0;
}
