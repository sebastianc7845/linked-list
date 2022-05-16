#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked-list.h"

static void free_list_help(Node **head);
static Node *new_node(void *data, size_t sizeof_data, Node *next_node);

LinkedList *new_list() {
  LinkedList *new;
  
  new = malloc(sizeof(*new));
  new->head = NULL;

  return new;
}

int append_node(LinkedList *list, void *data, size_t sizeof_data) {
  int ret = -1;
  
  if (list != NULL && data != NULL && sizeof_data > 0) {
    Node **curr_ptr = &(list->head), *temp = NULL;
    int i = 0;

    while (*curr_ptr != NULL) {
      curr_ptr = &((*curr_ptr)->next);
      i++;
    }

    temp = new_node(data, sizeof_data, NULL);

    if (temp != NULL) {
      ret = i;
      *curr_ptr = temp;
    }
  }

  return ret;
}

int insert_node(LinkedList *list, void *data, size_t sizeof_data,
		 int index) {
  int ret = -1;
  
  if (list != NULL && data != NULL && sizeof_data > 0 && index > -1) {
    Node *curr = list->head;
    Node *prev = NULL;
    int i = 0;

    while (curr != NULL && i < index) {
      prev = curr;
      curr = curr->next;
      i++;
    }

    if (i == index) {
      Node *new;
      
      new = new_node(data, sizeof_data, curr);

      if (new != NULL) {
	ret = 1;
	
	if (prev != NULL)
	  prev->next = new;
	else
	  list->head = new;
      }
    }
  }
  return ret;
}

int remove_node(LinkedList *list, int index) {
  int ret = 0;

  if (list != NULL && index > -1) {
    Node *curr = list->head, *prev = NULL;
    int i = 0;

    while (curr != NULL && i < index) {
      prev = curr;
      curr = curr->next;
      i++;
    }

    if (i == index) {
      ret = 1;
      
      if (prev != NULL)
	prev->next = curr->next;
      else
	list->head = NULL;
      curr->next = NULL;

      free(curr->data);
      free(curr);
    }
  }

  return ret;
}

void print_list(LinkedList *list, void (*print_node_ptr) (void *)) {
  if (list != NULL && print_node_ptr != NULL) {
    Node *curr = list->head;
    int i = 0;
    
    while (curr != NULL) {
      printf("index %d: ", i);
      print_node_ptr(curr->data);
      printf("\n");

      curr = curr->next;
      i++;
    }
  }
  
}

void free_list(LinkedList *list) {
  if (list != NULL) {
    free_list_help(&(list->head));
    free(list);
  }
}

static void free_list_help(Node **head) {
  if (head != NULL && (*head) != NULL) {
    free_list_help(&((*head)->next));

    free((*head)->data);
    free(*head);
  }
}

static Node *new_node(void *data, size_t sizeof_data, Node *next_node) {
  Node *new;
  new = malloc(sizeof(*new));
  
  if (new != NULL) {
    new->data = malloc(sizeof(sizeof_data));
    
    if (new->data != NULL) {
      new->data_sz = sizeof_data;
      memcpy(new->data, data, sizeof_data);
      new->next = next_node;
    } else {
      free(new);
      new = NULL;
    }
  }

  return new;
}
