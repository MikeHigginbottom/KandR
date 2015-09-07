#include <stdio.h>
#include <string.h>
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

/*
Reverse and return the passed in string
*/
void reverse(char s[]) {
  int len = strlen(s) ;
  int temp, front, back;
  for (front = 0, back = len-1; front < back; front++, back--)
    {
      temp = s[front];
      s[front] = s[back];
      s[back] = temp;
    }
}

/*
Replace tabs in the input with the proper number of
blanks to space to the next tab stop.
Assume a fixed set of tab stops, every tabWidth columns.
*/

char *detabify(char input[], char output[], int tabWidth) {
  int inchpos, outchpos, wsreqd, wschpos;
  int len = strlen(input);
  for (inchpos = 0, outchpos = 0; inchpos < len; ++inchpos) {
    if (input[inchpos] != '\t') {
      output[outchpos++] = input[inchpos];
    }
    else {
      wsreqd = tabWidth - (outchpos % tabWidth);
      for (wschpos = 1; wschpos <= wsreqd; ++wschpos)
	output[outchpos++] = ' ';
    }
  }
  output[outchpos] = '\0';
  return output;
} 

