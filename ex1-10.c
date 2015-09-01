#include <stdio.h>

int main(void)
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
			printf("\\t");
		else if (c == '\b') /* this never fires (backspace chars are not added to the buffered line) - feature of termios? */
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	return 0;
}
