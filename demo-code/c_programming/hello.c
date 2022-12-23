#include <stdio.h>

int print_message(char*);
int change_number_to_10(int*);

int main(void) {
  //char * print_me = "Hello\n";
  //print_message(print_me);
  int my_number = 1;
  // Should print 1
  printf("%d %s", my_number, "\n");
  // Should print 10
  change_number_to_10(&my_number);
  printf("%d %s", my_number, "\n");
  return 0;
}

int change_number_to_10(int *num) {
  int ten = 10;
  *num = ten;
  return 0;
}

int print_message(char* to_print) {
  printf("%s", to_print);
  return 0;
}
