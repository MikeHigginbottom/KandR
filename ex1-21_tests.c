#include <stdio.h>
#include <string.h>
#include "kandr.h"
#include "test_framework.h"

#define MAXLINE 1000
#define TABWIDTH 4

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

int testEmptyInput(void) {
  char *input = "";
  char *expected = "";
  char output[MAXLINE] = "";
  tf_assert(strcmp(entab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testNoBlanks(void) {
  char *input = "abcdefghi";
  char *expected = "abcdefghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(entab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testSingleBlanks(void) {
  char *input = " abcd efgh ijkl mnop qrst";
  char *expected = ".abcd.efgh.ijkl\tmnop.qrst";
  char output[MAXLINE] = "";
  tf_assert(strcmp(entab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testDoubleBlanks(void) {
  char *input = "  abc  def  ghi  jkl  mno";
  char *expected = "..abc..def\tghi\t.jkl..mno";
  char output[MAXLINE] = "";
  tf_assert(strcmp(entab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testLongBlanks(void) {
  char *input = "abc           def";
  char *expected = "abc\t\t\t..def";
  char output[MAXLINE] = "";
  tf_assert(strcmp(entab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

void test_suite(void) {
  tf_init_suite();
  tf_run_test(testEmptyInput);
  tf_run_test(testNoBlanks);
  tf_run_test(testSingleBlanks);
  tf_run_test(testDoubleBlanks);
  tf_run_test(testLongBlanks);
}

tf_run_suite(test_suite);
