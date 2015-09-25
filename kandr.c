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

char *detab(char input[], char output[], int tabWidth) {
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

/*
Replace strings of blanks by the minimum number of
tabs and blanks to achieve the same spacing.
When either a tab or a single blank would suffice to
reach a tab stop, use a tab
*/
char *entab(char input[], char output[], int tabWidth) {
  int inchpos, outchpos, startpos, inblanks;
  int tabs, blanks;
  int blanksRequired;
  int firstTabBuys;
  int extraTabsReqd;
  startpos = 0;
  inblanks = 0;
  outchpos = 0;
  for (inchpos = 0; inchpos < strlen(input); ++inchpos) {
    if (input[inchpos] != ' ') {
      if (inblanks) {
	blanksRequired = inchpos - startpos;
	firstTabBuys = tabWidth - (startpos % tabWidth);
	if (firstTabBuys <= blanksRequired) {
	  output[outchpos++] = '\t';
	  blanksRequired -= firstTabBuys;
	}
	extraTabsReqd = blanksRequired / tabWidth;
	for (tabs = 1; tabs <= extraTabsReqd; ++tabs) {
	  output[outchpos++] = '\t';
	  blanksRequired -= tabWidth;
	}
	for (blanks = 1; blanks <= blanksRequired; ++blanks) {
	  output[outchpos++] = '.';
	}
      }
      output[outchpos++] = input[inchpos];
      inblanks = 0;
    }
    else if (!inblanks) {
      startpos = inchpos;
      inblanks = 1;
    }
  }
  return output;
}

