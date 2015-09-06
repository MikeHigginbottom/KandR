/*remove trailing blanks and tabs from each line of input
delete entirely blank lines.*/

#include <stdio.h>
#include "kandr.h"

#define MAXLINE 1000

int main(void)
{
  int len, chpos;
  char line[MAXLINE];
  while ((len = mygetline(line, MAXLINE)) > 0) {
    chpos = len-1;
    while (line[chpos] == ' ' || line[chpos] == '\t' || line[chpos] == '\n')
      --chpos;
    line[chpos+1] = '\0';
    if (chpos >= 0)
      printf("Text: '%s'\n", line);
  }
  return 0;
}
