#include <stdio.h>

#define MAX_CHAR 255

int main(void) {
  int charCount[MAX_CHAR];
  unsigned char charIndex;
  int c, chpos;
  for (charIndex = 0; charIndex < MAX_CHAR; charIndex++) {
    charCount[charIndex] = 0;
  }
  while ((c = getchar()) != EOF) {
    charCount[c]++;
  }
  printf("\n");
  for (charIndex = 0; charIndex < MAX_CHAR; charIndex++) {
    if (charCount[charIndex] != 0) {
      if (charIndex <= 32) {
	printf("%2d ", charIndex);
      }
      else {
	printf("%c  ", charIndex);
      }
      for (chpos = 0; chpos < charCount[charIndex]; chpos++) {
	printf("*");
      }
      printf("\n");
    }
  }
  return 0;
}
