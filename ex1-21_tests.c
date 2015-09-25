#include <stdio.h>
#include <string.h>
#include "kandr.h"
#include "test_framework.h"

#define MAXLINE 1000
#define TABWIDTH 4

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
