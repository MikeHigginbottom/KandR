#include <stdio.h>

#define MAX_LENGTH 20

int main(void) {
  int wordFrequency[MAX_LENGTH+1];
  int inword, c, chpos, length;
  for (length = 0; length <= MAX_LENGTH; length++) {
    wordFrequency[length] = 0;
  }
  length = 0;
  inword = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (inword && length <= MAX_LENGTH) {
	wordFrequency[length]++;
	length = 0;	
	inword = 0;
      }
    }
    else {
      length++;
      inword = 1;
    }
  }
  length = 1;
  while (length <= MAX_LENGTH) {
    printf("%2d ", length);    
    for (chpos = 0; chpos < wordFrequency[length]; chpos++) {
      printf("*");
    }
    printf("\n");
    length++;
  }
  return 0;
}
