#include <stdio.h>
#include "linked-list.h"

void print_int(void *int_ptr);

int main(void) {
  LinkedList *l;
  int i,  nums[] = { 1, 4, 6, 1, 7, 8 };
  int new_num = 823213;
  
  l = new_list();

  for (i = 0; i < 6; i++)
    append_node(l, &(nums[i]), sizeof(nums[i]));

  print_list(l, print_int);

  insert_node(l, &new_num, sizeof(new_num), 3);
  print_list(l, print_int);
  
  free_list(l);
  
  return 0;
}

void print_int(void *int_ptr) {
  printf("%d", *(int *)int_ptr);
}
