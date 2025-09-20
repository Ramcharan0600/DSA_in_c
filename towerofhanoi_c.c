#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // If there's just one disk, move it straight from the source to the destination rod
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    // First, move n-1 disks from the source to the auxiliary rod, using destination as a helper
    towerOfHanoi(n - 1, source, destination, auxiliary);
    // Now, move the largest disk (nth disk) from the source to the destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    // Finally, move the n-1 disks from the auxiliary to the destination, using source as a helper
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n; 
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of disks must be positive!\n");
        return 1;
    }
    towerOfHanoi(n, 'A', 'B', 'C');
    
    return 0;
}