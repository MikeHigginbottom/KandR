#include <stdio.h>

int main(void)
{
	float lower = 0, upper = 300, step = 20;
	float fahr = lower, celsius;
	printf("%3s %6s\n", "F", "C");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}
	return 0;
}
