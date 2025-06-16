#include <8051.h> 
void main() 
{
	int i;
	char xdata *ptr; 
	char test, nabor;
	nabor = 0x55; 
	ptr = (char xdata *) 0x0AA; 
	for(i=0; i<1879;i++) {
		*ptr=nabor; 
		test=*ptr; 
	if(test!=nabor){
		break; 
	}
	ptr++;
	}
}
