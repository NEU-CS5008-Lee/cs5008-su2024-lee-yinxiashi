// Yinxia Shi
// shi.yinx@northeastern.edu
// To perform insertion sort of integers stored in a file and display the output and store it in another file.

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int arr[10], temp;
    int count = 0, i, j;
    /* count will have the total number of elements in the array */

    /* read the file */
    fp = fopen("Input1.txt", "r");

    if (fp == NULL) {
        // if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    //insert your code here

    // Keep reading until we get EOF
    while (1) {
        // Read an integer from the FILE
        fscanf(fp, "%d", &arr[count]);

        // If the read is successful.
        if (feof(fp) == 0) {
            // Increase the count
            count++;
        } 
        else {
            // Nothing to read, break.
            break;
        }
    }

    // Close the file
    fclose(fp);

    // Perform insertion sort.
    for (i = 1; i < count; i++) {

        // Remember the number to be inserted.
        temp = arr[i];

        // Scan the sorted part backwards.
        for (j = i - 1; j >= 0; j--) {
            // If the current number in the sorted part is greater than
            // the number to be inserted, we push this number to the right
            // and place the new number at this spot.
            if (temp < arr[j]) {
                arr[j + 1] = arr[j];
                arr[j] = temp;
            } else {
                // Otherwise, we are done with the current round of insertion.
                break;
            }
        }
    }

    // Open a new file to store the sorted list
    fp = fopen("sorted.txt", "w");

    if (fp == NULL) {
        // if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }

    // Print each number in the list to the screen and the new file.
    for (i = 0; i < count; i++) {
        // print to the screen.
        printf("%d\n", arr[i]);
        // print to the file.
        fprintf(fp, "%d\n", arr[i]);
    }

    // Close the new file.
    fclose(fp);

    return 0;
}
