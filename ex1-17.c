#include <stdio.h>
#include "kandr.h"

#define MAXLINE 1000

int main()
{
  int len;
  char line[MAXLINE];
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > 8)
      printf("%s", line);
  return 0;
}
