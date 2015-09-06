#include <stdio.h>
#include "kandr.h"

#define MAXLINE 10

int main(void)
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) {
    printf("Length: %d\n", max);
    printf("Text: %s\n", longest);
  }
  return 0;
}
