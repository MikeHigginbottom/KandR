#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORDS 0

int main(void)
{
	int c, nl, nw, nc, state;
	state = OUTSIDE_WORDS;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUTSIDE_WORDS;
		else if (state == OUTSIDE_WORDS) {
			state = INSIDE_WORD;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
