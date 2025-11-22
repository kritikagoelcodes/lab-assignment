#include <stdio.h>

void improvedSelectionSort(int a[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int min = start, max = start;

        for (int i = start; i <= end; i++) {
            if (a[i] < a[min])  min = i;
            if (a[i] > a[max])  max = i;
        }

        // Swap minimum to front
        int t = a[start];
        a[start] = a[min];
        a[min] = t;

        // Fix if max element was swapped earlier
        if (max == start) max = min;

        // Swap maximum to end
        t = a[end];
        a[end] = a[max];
        a[max] = t;

        start++;
        end--;
    }
}

int main() {
    int a[] = {64, 25, 12, 22, 11, 90};
    int n = 6;

    improvedSelectionSort(a, n);

    printf("Improved Selection Sort (Min+Max): ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
