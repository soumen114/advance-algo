#include <stdio.h>

int heap_size;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// MaxHeapify function: maintains the max-heap property
void max_heapify(int A[], int i) {
    int l = 2 * i + 1;       // Left child (0-based indexing)
    int r = 2 * i + 2;       // Right child
    int largest = i;

    if (l < heap_size && A[l] > A[largest])
        largest = l;
    if (r < heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        max_heapify(A, largest);
    }
}

// Build a max heap from the array
void build_max_heap(int A[], int length) {
    heap_size = length;
    for (int i = (length / 2) - 1; i >= 0; i--) {
        max_heapify(A, i);
    }
}

// Heap sort algorithm
void heap_sort(int A[], int length) {
    build_max_heap(A, length);
    for (int i = length - 1; i > 0; i--) {
        swap(&A[0], &A[i]);
        heap_size--;
        max_heapify(A, 0);
    }
}

// Function to print array
void print_array(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int n;

    // Take input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Perform heap sort
    heap_sort(A, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(A, n);

    return 0;
}
