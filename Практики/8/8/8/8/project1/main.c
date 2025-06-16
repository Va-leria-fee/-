#include <8051.h>


void obrabotka();
interrupt void on_button() {
	obrabotka();
}

int i;
int n;
int x;
int pausa;


void pause(char p) {
	TH1 = 0xFF; // старший байт
	TL1 = 0xFF - p; // младший байт
	TF1 = 0; // бит управления таймера
	TR1 = 1; // флаг переполнения таймера
	while (TF1 == 0);
	TR1 = 0; 
	TL1 = 0; 
}

void segment() {
	for (i = 0; i < n; i++) {
		P0 += x;
		pause(pausa);
	}
}

void main()
{
	int x1;
	int x2;
	int x3;
	
	// n = 32
	// x1 = (256-64) / n = 6
	// x2 = 0
	// x3 = (128-256) / n = -4
	
	x1 = 6;
	x2 = 0;
	x3 = -4;
	
	pausa = 1;
	n = 32;
	P0 = 0;
	P1 = 0;
	P3 = 0;
	TMOD = 0b00010000; // T/C1 в режиме 1

	// настройка системы прерываний по INT0:
	IE = 	0b10000001;
	TCON = 	0b00000011;
	

	while(1){
		P0 = 0;
		x = 0;
		segment();
		
		P0 = 63;
		x = x1;
		segment();
		
		P0 = 255;
		x = x2;
		segment();
		
		P0 = 255;
		x = x3;
		segment();
		
		P0 = 0;
		x = 0;
		segment();
	}
}

void obrabotka() {
	P10 = 1;
	P10 = 0;
	
	pausa += 20 * P11;
	pausa -= 20 * P12;
	if (pausa < 1) pausa = 1;
	if (pausa > 255) pausa = 255;
	
}