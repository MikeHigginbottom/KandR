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
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testNoTabs(void) {
  char *input = "abcdefghi";
  char *expected = "abcdefghi";
  char output[MAXLINE];
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testFirstCharTab(void) {
  char *input = "\tabcdefghi";
  char *expected = "    abcdefghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testSecondCharTab(void) {
  char *input = "a\tbcdefghi";
  char *expected = "a   bcdefghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testThirdCharTab(void) {
  char *input = "ab\tcdefghi";
  char *expected = "ab  cdefghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testFourthCharTab(void) {
  char *input = "abc\tdefghi";
  char *expected = "abc defghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testFifthCharTab(void) {
  char *input = "abcd\tefghi";
  char *expected = "abcd    efghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

int testConsecutiveTabs(void) {
  char *input = "ab\t\tcdefghi";
  char *expected = "ab      cdefghi";
  char output[MAXLINE] = "";
  tf_assert(strcmp(detab(input, output, TABWIDTH), expected) == 0, "Expected '%s' was '%s'", expected, output);
  tf_passed();
}

void test_suite(void) {
  tf_init_suite();
  tf_run_test(testEmptyInput);
  tf_run_test(testNoTabs);
  tf_run_test(testFirstCharTab);
  tf_run_test(testSecondCharTab);
  tf_run_test(testThirdCharTab);
  tf_run_test(testFourthCharTab);
  tf_run_test(testFifthCharTab);
  tf_run_test(testConsecutiveTabs);
}

tf_run_suite(test_suite);
