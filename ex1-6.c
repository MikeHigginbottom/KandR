#include <stdio.h>

int main(void)
{
	int result;
	printf("Press a key. You may need to press ENTER afterwards depending on your terminal emulator's buffering method.\n");
	while (result = (getchar() != EOF))
		printf("Not EOF %d\n", result);
	printf("EOF %d\n", result);
	return 0;
}
