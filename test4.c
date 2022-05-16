#include "stdio.h"
#include "linked-list.h"

void print_int(void *num);

int main(void) {
  LinkedList *l;
  int i, insert_ret, nums[] = { 1, 6, 7, 8, 2, 5 };
  int another_int = 45;
  l = new_list();

  for (i = 0; i < 6; i++)
    append_node(l, &nums[i], sizeof(nums[i]));
  print_list(l , print_int);

  insert_ret = insert_node(l, &another_int, sizeof(another_int), 0);
  printf("insert returned: %d\n", insert_ret);
  print_list(l , print_int);
  
  return 0;
}

void print_int(void *num) {
  printf("%d", *(int *)num);
}
