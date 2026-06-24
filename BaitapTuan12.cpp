#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);

        printf("Swap %d va %d: ", a[largest], a[i]);
        printArray(a, n);

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    printf("Mang ban dau: ");
    printArray(a, n);

    printf("\n=== Qua trinh vun dong Max Heap ===\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        printf("Heapify tai i = %d: ", i);
        heapify(a, n, i);
        printArray(a, n);
    }

    printf("\nMax Heap sau khi vun dong: ");
    printArray(a, n);

    printf("\n=== Qua trinh sap xep ===\n");
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);

        printf("\nDua max ve cuoi, i = %d: ", i);
        printArray(a, n);

        printf("Vun dong lai phan con lai: \n");
        heapify(a, i, 0);

        printf("Trang thai sau khi heapify: ");
        printArray(a, n);
    }
}

int main() {
    int a[] = {11, 59, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};
    int n = sizeof(a) / sizeof(a[0]);

    heapSort(a, n);

    printf("\nMang sau khi sap xep tang dan: ");
    printArray(a, n);

    return 0;
}