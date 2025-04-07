#include <stdio.h>
#include <math.h>  // for floor()

void merge(float A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    float L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }
}

void mergeSort(float A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float A[n];

    printf("Enter %d numbers :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &A[i]);
    }

    mergeSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        if (A[i] == (int)A[i])
            printf("%d ", (int)A[i]);       // Print as int if no decimal part
        else
            printf("%.1f ", A[i]);          // Print as float otherwise
    }
    printf("\n");

    return 0;
}
