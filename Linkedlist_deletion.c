#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};
struct node* start = NULL;

void insertBeg(int num) {
  // Create a new node and set its data
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = num;
  // Point new node to current start, then update start to new node
  new_node->next = start;
  start = new_node;
}

void traversal() {
  if (start == NULL) {
    printf("Empty\n");
    return;
  }
  struct node* ptr = start;
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL\n");
}

void deleteBeg() {
  // If list is empty, nothing to delete
  if (start == NULL) {
    printf("Empty\n");
    return;
  }
  // If only one node, free it and set start to NULL
  if (start->next == NULL) {
    free(start);
    start = NULL;
    return;
  }
  // Store start node, move start to next node, free old start
  struct node* temp = start;
  start = start->next;
  free(temp);
}

void deleteEnd() {
  // If list is empty, nothing to delete
  if (start == NULL) {
    printf("Empty\n");
    return;
  }
  // If only one node, free it and set start to NULL
  if (start->next == NULL) {
    free(start);
    start = NULL;
    return;
  }
  // Find second-to-last node and last node
  struct node* ptr = start, *preptr = NULL;
  while (ptr->next != NULL) {
    preptr = ptr;
    ptr = ptr->next;
  }
  // Disconnect last node and free it
  preptr->next = NULL;
  free(ptr);
}

void deleAtPos(int val) {
  // If list is empty, nothing to delete
  if (start == NULL) {
    printf("Empty\n");
    return;
  }
  // If only one node and it matches val, free it and set start to NULL
  if (start->next == NULL && start->data == val) {
    free(start);
    start = NULL;
    return;
  }
  // Find node with val and its previous node
  struct node* ptr = start, *preptr = NULL;
  while (ptr != NULL && ptr->data != val) {
    preptr = ptr;
    ptr = ptr->next;
  }
  // If val found, skip the node and free it
  if (ptr != NULL && ptr->data == val) {
    preptr->next = ptr->next;
    free(ptr);
  } else {
    printf("Value not found\n");
  }
}

int main() {
  int choice, num, val;
  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("Enter number to insert: ");
        scanf("%d", &num);
        insertBeg(num);
        break;
      case 2:
        traversal();
        break;
      case 3:
        deleteBeg();
        break;
      case 4:
        deleteEnd();
        break;
      case 5:
        printf("Enter value to delete: ");
        scanf("%d", &val);
        deleAtPos(val);
        break;
      case 6:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }
}