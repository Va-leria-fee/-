#include <8051.h>

void f(){
	P0 = 0x01;
	P22 = 0; 			// RW 
	P21 = 0;            // RS
	P20 = 1;
	P20 = 0;            // E
}

char func() {
	int g = -1, v = -1, i = 0;
	char s;
	
	P1 = 0xFF;
	P3 = 0;
	if (P10 == 0)
		g = 0;
	if (P11 == 0)
		g = 1;
	if (P12 == 0)
		g = 2;
	if (P13 == 0)
		g = 3;	
	
	P3 = 0xFF;
	P1 = 0;
	if (P30 == 0)
		v = 0;
	if (P31 == 0)
		v = 1;
	if (P32 == 0)
		v = 2;
	if (P33 == 0)
		v = 3;
	
	if (g == 0 && v == 0){
		f();
		}
	if (g == 0 && v == 1)
		s = '0';
	if (g == 0 && v == 2)
		s = '=';
	if (g == 0 && v == 3)
		s = '/';
	
	if (g == 1 && v == 0)
		s = '1';
	if (g == 1 && v == 1)
		s = '2';
	if (g == 1 && v == 2)
		s = '3';
	if (g == 1 && v == 3)
		s = '*';
	
	if (g == 2 && v == 0)
		s = '4';
	if (g == 2 && v == 1)
		s = '5';
	if (g == 2 && v == 2)
		s = '6';
	if (g == 2 && v == 3)
		s = '-';
	
	if (g == 3 && v == 0)
		s = '7';
	if (g == 3 && v == 1)
		s = '8';
	if (g == 3 && v == 2)
		s = '9';
	if (g == 3 && v == 3)
		s = '+';
	
	if (g == -1 && v == -1)
		s = '.';
	
	if (s != '.' && s != '=' && s != 'C') {
		P0 = s;
		P21 = 1;
		P22 = 0;
		P20 = 1;
		P20 = 0;
		for (i = 0; i < 10; i++);
	}
	return s;
}

int number(int n, char s){
	n = n * 10 + s - 0x30;
	return(n);
}

void answer (char n){
	P0 = n + 0x30;
	P21 = 1;
	P22 = 0;
	P20 = 1;
	P20 = 0;
	}

void main() {
	
	char s;
	int flag = 0;
	int n = 0, a = 0, b = 0, i = 0, j = 0, k = 0;
	char mass[5];
	
	while (1){
		s = func();
		if (s != '.' && s != '+' && s != '-' && s != '*' && s != '/') {
			a = number(a, s);
		}
		else n = 0;

		if (s == '+') {
			s = func();
			while (s != '+' && s != '-' && s != '*' && s != '/' && s != '=') {
				if (s != '.') {
					b = number(b, s);
				}
				s = func();
			}
			n = a + b;
			f();
			i = 0;
			while (n > 0) {
				mass[i] = n % 10;
				n = n / 10;
				i++;
			}
			for (j = 0; j < i; i--) {
				k = mass[i - 1];
				answer(k);
			}

			i = 0;
			a = 0;
			b = 0;
			n = 0;
		}

		if (s == '-') {
			s = func();
			while (s != '+' && s != '-' && s != '*' && s != '/' && s != '=') {
				if (s != '.') {
					b = number(b, s);
				}
				s = func();
			}
			n = a - b;
			f();
			i = 0;
			while (n > 0) {
				mass[i] = n % 10;
				n = n / 10;
				i++;
			}
			for (j = 0; j < i; i--) {
				k = mass[i - 1];
				answer(k);
			}

			i = 0;
			a = 0;
			b = 0;
			n = 0;
		}

		if (s == '*') {
			s = func();
			while (s != '+' && s != '-' && s != '*' && s != '/' && s != '=') {
				if (s != '.') {
					b = number(b, s);
				}
				s = func();
			}
			n = a * b;
			f();
			i = 0;
			while (n > 0) {
				mass[i] = n % 10;
				n = n / 10;
				i++;
			}
			for (j = 0; j < i; i--) {
				k = mass[i - 1];
				answer(k);
			}

			i = 0;
			a = 0;
			b = 0;
			n = 0;
		}

		if (s == '/') {
			s = func();
			while (s != '+' && s != '-' && s != '*' && s != '/' && s != '=') {
				if (s != '.') {
					b = number(b, s);
				}
				s = func();
			}
			if (b != 0) {
				n = a / b;
				f();
				i = 0;
				while (n > 0) {
					mass[i] = n % 10;
					n = n / 10;
					i++;
				}
				for (j = 0; j < i; i--) {
					k = mass[i - 1];
					answer(k);
				}
			}
			else 
				f();
			i = 0;
			a = 0;
			b = 0;
			n = 0;
		}
	}
}