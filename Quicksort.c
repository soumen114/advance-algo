#include <stdio.h>

// Swap function
void interch(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Quick Sort based on the provided algorithm
void Qsort(float a[], int m, int n) {
    if (m < n) {
        float key = a[m];
        int i = m, j = n + 1;

        while (1) {
            do { i++; } while (i <= n && a[i] < key);
            do { j--; } while (a[j] > key);

            if (i < j)
                interch(&a[i], &a[j]);
            else
                break;
        }

        interch(&a[m], &a[j]);
        Qsort(a, m, j - 1);
        Qsort(a, j + 1, n);
    }
}

// Print array (auto format int or float)
void printArray(float a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == (int)a[i])
            printf("%d ", (int)a[i]);
        else
            printf("%.2f ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float a[n];
    printf("Enter %d numbers (int or float):\n", n);
    for (int i = 0; i < n; i++) scanf("%f", &a[i]);

    printf("Original array: ");
    printArray(a, n);

    Qsort(a, 0, n - 1);

    printf("Sorted array:   ");
    printArray(a, n);

    return 0;
}