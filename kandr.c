#include <stdio.h>
#include "kandr.h"

/*
Returns a line up to maxChars chars long
Includes terminating \n if found in the buffer within maxChars limit
Adds final terminating \0 under all circumstances
Characters beyond the maxChars limit are not added to the returned string
but are included in the returned character count
*/
int mygetline(char line[], int maxChars) {
  int c, inCharPos, outCharPos;
  for (inCharPos = 0, outCharPos = 0; (c = getchar()) != EOF && c != '\n'; ++inCharPos) {
    if (inCharPos < maxChars-1) {
      line[outCharPos++] = c;
    }
  }
  if (c == '\n') {
    if (inCharPos <= maxChars-1) {
      line[outCharPos++] = c;
    }
    ++inCharPos;
  }
  line[outCharPos] = '\0';
  return inCharPos;
}

/*
Naive string copy - assumes destination string is
large enough to hold a copy of the source string
*/
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
