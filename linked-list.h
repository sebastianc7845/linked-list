#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct node {
  size_t data_sz;
  void *data;
  struct node *next;
} Node;

typedef struct {
  Node *head;
} LinkedList;

LinkedList *new_list();
int append_node(LinkedList *list, void *data, size_t sizeof_data);
int insert_node(LinkedList *list, void *data, size_t sizeof_data,
		 int index);
int remove_node(LinkedList *list, int index);
void print_list(LinkedList *list, void (*print_node_ptr) (void *));
void free_list(LinkedList *list);
#endif
