#include <stdio.h>
#include <math.h>

double c_func(int x, int k) {
	double a = 1;

	if (k != 0 && x != 0) {
		for (int i = 0; i < k; i++)
			a *= x;
		a = 1 / a;
		a = a / sin(k * x);
	}
	else
		return 0;

	return a;
}



