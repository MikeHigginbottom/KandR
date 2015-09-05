#include <stdio.h>

float toCelsius(float fahr) {
	return (5.0/9.0) * (fahr-32.0);
}

int main(void)
{
	float lower = 0, upper = 300, step = 20;
	float fahr = lower;
	printf("%3s %6s\n", "F", "C");
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, toCelsius(fahr));
		fahr += step;
	}
	return 0;
}
