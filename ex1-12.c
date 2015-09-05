#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORDS 0

int main(void)
{
	int c, state;
	state = OUTSIDE_WORDS;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == INSIDE_WORD)
				putchar('\n');
			state = OUTSIDE_WORDS;
		}
		else {
			putchar(c);
			if (state == OUTSIDE_WORDS) {
				state = INSIDE_WORD;
			}
		}
	}
	return 0;
}
