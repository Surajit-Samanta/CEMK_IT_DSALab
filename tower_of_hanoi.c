#include <stdio.h>

// Function to move a disk from one rod to another
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int numDisks = 3; // Number of disks
    char sourceRod = 'A'; // Source rod
    char destinationRod = 'C'; // Destination rod
    char auxiliaryRod = 'B'; // Auxiliary rod

    // Function call to solve the Tower of Hanoi problem
    towerOfHanoi(numDisks, sourceRod, destinationRod, auxiliaryRod);

    return 0;
}
