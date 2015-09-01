#include <stdio.h>

int main(void)
{
	int c, inws;
	inws = 0;
	while ((c = getchar()) != EOF) {
		if (!(inws && c==' ')) {
			putchar(c);
		}
		inws = (c == ' ');
	}
	return 0;
}
