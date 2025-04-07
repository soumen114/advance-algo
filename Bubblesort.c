

#include <stdio.h>
#include <math.h>

// Swap function
void swap(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort function
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Print array function
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == (int)arr[i]) {
            printf("%d ", (int)arr[i]);
        } else {
            printf("%.2f ", arr[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d elements :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}
