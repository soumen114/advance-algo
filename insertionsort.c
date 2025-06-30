#include <stdio.h>

// Insertion Sort for integer array
void insertion_sort_int(int arr[], int n) {
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

// Insertion Sort for float array
void insertion_sort_float(float arr[], int n) {
    int i, j;
    float key;
    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

// Print integer array
void print_int_array(int arr[], int n) {
    printf("Sorted Integer Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Print float array
void print_float_array(float arr[], int n) {
    printf("Sorted Float Array: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int choice, n;

    printf("Choose array type:\n");
    printf("1. Integer Array\n");
    printf("2. Float Array\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (choice == 1) {
        int arr[n];
        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        insertion_sort_int(arr, n);
        print_int_array(arr, n);
    } else if (choice == 2) {
        float arr[n];
        printf("Enter %d float numbers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%f", &arr[i]);
        }
        insertion_sort_float(arr, n);
        print_float_array(arr, n);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
