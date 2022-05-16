#include "stdio.h"
#include "linked-list.h"

struct person {
  double bank_balance;
  int age;
};

void print_person(void *dude);

int main(void) {
  LinkedList *l;
  int i;
  struct person p1, p2, p3;
  struct person *person_arr[3];

  p1.bank_balance = 12.3;
  p1.age = 19;
  p2.bank_balance = 1204.89;
  p2.age = 36;
  p3.bank_balance = 851540.22;
  p3.age = 52;

  person_arr[0] = &p1;
  person_arr[1] = &p2;
  person_arr[2] = &p3;
  
  l = new_list();

  for (i = 0; i < 3; i++)
    append_node(l, person_arr[i], sizeof(struct person));

  print_list(l, print_person);

  p3.age = 13;

  print_list(l, print_person);

  free_list(l);
  
  return 0;
}

void print_person(void *dude) {
  printf("\nbalance: %f\n", ((struct person *)dude)->bank_balance);
  printf("age: %d", ((struct person *)dude)->age);
}
