#include <stdio.h>

int main(void)
{
	float lower = 0, upper = 300, step = 20;
	float celsius = lower, fahr;
	printf("%3s %6s\n", "C", "F");
	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
