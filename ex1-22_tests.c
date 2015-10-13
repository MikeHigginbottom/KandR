#include <stdio.h>
#include <string.h>
#include "kandr.h"
#include "test_framework.h"

#define MAXLINE 1000
#define FOLDPOINT 5

int testEmptyInput(void) {
	char *input = "";
	char *expected = "";
	char output[MAXLINE] = "";
	tf_assert(strcmp(fold(input, output, FOLDPOINT), expected) == 0, "Expected '%s' was '%s'", expected, output);
	tf_passed();
}

int testSingleCharacter(void) {
	char *input = "a";
	char *expected = "a";
	char output[MAXLINE] = "";
	tf_assert(strcmp(fold(input, output, FOLDPOINT), expected) == 0, "Expected '%s' was '%s'", expected, output);
	tf_passed();
}

int testNoFoldRequired(void) {
	char *input = "abcd";
	char *expected = "abcd";
	char output[MAXLINE] = "";
	tf_assert(strcmp(fold(input, output, FOLDPOINT), expected) == 0, "Expected '%s' was '%s'", expected, output);
	tf_passed();
}

int testOverLongWord(void) {
	char *input = "abcde";
	char *expected = "abcd.e";
	char output[MAXLINE] = "";
	tf_assert(strcmp(fold(input, output, FOLDPOINT), expected) == 0, "Expected '%s' was '%s'", expected, output);
	tf_passed();
}

int testBasicFolding(void) {
	char *input = "abc def";
	char *expected = "abc.def";
	char output[MAXLINE] = "";
	tf_assert(strcmp(fold(input, output, FOLDPOINT), expected) == 0, "Expected '%s' was '%s'", expected, output);
	tf_passed();
}

int testSkipAFoldPoint(void) {
	char *input = "a b c de f";
	char *expected = "a b.c de.f";
	char output[MAXLINE] = "";
	tf_assert(strcmp(fold(input, output, FOLDPOINT), expected) == 0, "Expected '%s' was '%s'", expected, output);
	tf_passed();
}

void test_suite(void) {
	tf_init_suite();
	tf_run_test(testEmptyInput);
	tf_run_test(testSingleCharacter);
	tf_run_test(testNoFoldRequired);
	tf_run_test(testOverLongWord);
	tf_run_test(testBasicFolding);
	tf_run_test(testSkipAFoldPoint);
}

tf_run_suite(test_suite);
