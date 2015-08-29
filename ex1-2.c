#include <stdio.h>

int main(void) {
  printf("\\a (alert) may or may not give an audible alert depending on the terminal emulator.\a\n");  
  printf("\\f (form feed) may or may not clear the screen depending on the terminal emulator.\f\n");
  printf("\\r (carriage return) moves the cursor to the start of the current line. Subsequent output will overwrite the content of this line e.g.:\n");
  printf("Current Line\rSubsequent Output\n");
  printf("\\v (vertical tab) may or may not move the cursor vertically downwards depending on the terminal emulator e.g:\n");
  printf("Current Line\vSubsequent Output\n");
  printf("\\z is an unrecognised control sequence and should emit a commpiler warning.\z\n");
  return 0;
}
