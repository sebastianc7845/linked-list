#include <stdio.h>
#include <string.h>
#include "linked-list.h"

void print_string(void *string_ptr);

int main(void) {
  LinkedList *l;
  int i;
  char *words[] = { "word1", "word2", "word3",
		    "abcde", "yea", "ue" };
  
  l = new_list();

  for (i = 0; i < 6; i++) {
    printf("string length: %d\n", (int) strlen(words[i]) + 1 );
    append_node(l, words[i], strlen(words[i]) + 1);
  }

  print_list(l, print_string);

  return 0;
}

void print_string(void *string_ptr) {
  printf("%s", (char *)string_ptr);
}
