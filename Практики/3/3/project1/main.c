#include <8051.h>
#include <string.h>

	int i;
	int j;
	int e;
	int l;

void str (unsigned char x) {
	P0 = x;
	P22 = 0; 			// RW 
	P21 = 1;            // RS
	P20 = 1;
	P20 = 0;            // E
}

void comm (unsigned char x) {
	P0 = x;
	P22 = 0; 			// RW 
	P21 = 0;            // RS
	P20 = 1;
	P20 = 0;            // E
} 

void main()
{
	unsigned char massiv [] = { 
		159 + 3, 
		159 + 1, 
		159 + 13, 
		159 + 6, 
		159 + 18, 
		159 + 10, 
		159 + 33
	};

	unsigned char massiv2 [] = { 
		159 + 31, 
		159 + 2, 
		159 + 6, 
		159 + 18, 
		159 + 13, 
		159 + 10, 
		159 + 15, 
		159 + 4
	};

	i = 0;
	j = 0;
	e = 2;

l = strlen(massiv);
		comm (0x04);
		comm (0xC0);
		str (' ');

		for (i = 7 - 1; i >= 0; i--)
			str (massiv[i]);

	while (1){	
		l = strlen(massiv2);
		comm (0x06);
		comm (0xC0);

		if (e <= l) {
			for (i = 0; i < e; i++) { 
				str (massiv2[l-e+i]);		
			}
			e = e + 2;
		}

		else {
	
			comm (0xC0 + j);
			str (' ');
			str (' ');
			j = j + 2;
		  
			if (j + l >= 16) {
				for (i = 0; i < 16 - j; i++)
					str (massiv2[i]);			
			}
			else {
				for (i = 0; i < l; i++) 
					str (massiv2[i]);			
			}
			if (j >= 16){
				j = 0;
				e = 0;
			}
		}
	}
}
