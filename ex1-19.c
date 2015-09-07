#include <stdio.h>
#include "kandr.h"

#define MAXLINE 1000

int main(void)
{
  char line[MAXLINE];
  while (mygetline(line, MAXLINE) > 0) {
    reverse(line);
    printf("'%s'\n", line);
  }
  return 0;
}
