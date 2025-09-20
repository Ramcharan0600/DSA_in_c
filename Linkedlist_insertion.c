#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* next;
};
struct node* start = NULL;

void insertBeg(int num) {
  // Create a new node and set its data
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = num;
  // If list is empty, make the new node point to itself and set as start
  if (start == NULL) {
    new_node->next = new_node;
    start = new_node;
  }
  // Find the last node in the circular list
  struct node* ptr = start;
  while (ptr->next != start) {
    ptr = ptr->next;
  }
  // Link new node to start, and last node to new node, update start
  new_node->next = start;
  ptr->next = new_node;
  start = new_node;
}

void insertEnd(int num) {
  // Create a new node and set its data
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = num;
  // If list is empty, make the new node point to itself and set as start
  if (start == NULL) {
    new_node->next = new_node;
    start = new_node;
  }
  // Find the last node in the circular list
  struct node* ptr = start;
  while (ptr->next != start) {
    ptr = ptr->next;
  }
  // Link last node to new node, and new node to start
  ptr->next = new_node;
  new_node->next = start;
}

void insertAfter(int num, int val) {
  // Check if list is empty
  if (start == NULL) {
    printf("Empty");
  }
  // Create a new node and set its data
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = num;
  // Find the node with value val
  struct node* ptr = start;
  while (ptr->next != start && ptr->data != val) {
    ptr = ptr->next;
  }
  // If val is found, insert new node after it
  if (ptr->data == val) {
    new_node->next = ptr->next;
    ptr->next = new_node;
  }
}

void traversal() {
  if (start == NULL) {
    printf("Empty");
  }
  struct node* ptr = start;
  do {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  } while (ptr != start);
  printf("\n");
}

int main() {
  insertBeg(7);
  insertBeg(6);
  insertBeg(5);
  traversal();
  insertEnd(10);
  traversal();
  insertEnd(8);
  insertEnd(9);
  traversal();
  insertAfter(11, 7);
  traversal();
}