#include <stdio.h>
/*
time complexity
bubble sort:
best = O(n)
worst, average = O(n^2)
selectionsort: (Greater than Bubble and less than insertion sort)
best, average, worst = O(n^2)
Insertion Sort: (fastest)
best = O(n)
worst, average = O(n^2)
*/
int bubblesort(int arr[], int n) {
  // Loop through the array
  for (int i = 0; i < n; i++) {
    // Compare adjacent elements and swap if out of order
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        // Swap elements to put smaller one first
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int selectionsort(int arr[], int n) {
  // Loop through each position
  for (int i = 0; i < n - 1; i++) {
    // Find the smallest element's index
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    // Swap smallest element with current position
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}
void insertionsort(int arr[], int n) {
  // Start from second element
  for (int i = 1; i < n; i++) {
    // Pick current element as key
    int key = arr[i];
    int j = i - 1;
    // Shift larger elements to the right
    while (arr[j] > key && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    // Place key in its correct spot
    arr[j + 1] = key;
  }
}
void dispaly(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main() {
  int n;
  int a[5] = {2, 2, 2, 2, 2};
  n = sizeof(a) / sizeof(a[0]);
  bubblesort(a, n);
  dispaly(a, n);
  selectionsort(a, n);
  dispaly(a, n);
  insertionsort(a, n);
  dispaly(a, n);
}