#include <stdio.h>

// Swap function for floats
void intch(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Selection Sort function
void Selection_sort(float a[], int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        j = i;
        for (k = j + 1; k < n; k++) {
            if (a[k] < a[j]) {
                j = k;
            }
        }
        if (i != j) {
            intch(&a[i], &a[j]);
        }
    }
}

// Function to print the array (auto format)
void printArray(float a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == (int)a[i])
            printf("%d ", (int)a[i]);   // Print as int if no decimal part
        else
            printf("%.2f ", a[i]);      // Print as float otherwise
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float a[n];

    printf("Enter %d numbers (can be negative and decimal):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    printf("Original array:\n");
    printArray(a, n);

    Selection_sort(a, n);

    printf("Sorted array:\n");
    printArray(a, n);

    return 0;
}