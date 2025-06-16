#include <8051.h>
void main()
{
	unsigned char i,j,x;
	unsigned char massiv [11]=
	{
	0xC0, 
	0xF9,
	0xA4,
	0xB0,
	0x99,
	0x92,
	0x82,
	0xF8,
	0x80,
	0x90,
	};
	unsigned char massiv2 [11]=
	{
	0x90,
	0x80,
	0xF8,
	0x82,
	0x92,
	0x99,	
	0xB0,
	0xA4,
	0xF9,
	0xC0,
	};

	P1=massiv [10];
	P3 = 0;
	i = 0;
	while(1) {
	while (P30 == 0){ 
		P2 = massiv[i];
		for(j=0;j<100;j++)
			continue;
		i+=1;
		if(i>9) i=0;
	}
	i-=1;
	while (P30 == 1){
		P2 = massiv[i];
		for(j=0;j<100;j++)
			continue;
		i-=1;
		if(i<1){
			P2 = massiv[i];
			for(j=0;j<100;j++)
				continue;
			i=9;
		}
		}
	i+=1;
	}
}
