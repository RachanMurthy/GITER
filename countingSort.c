#include <stdio.h>

/* Counting sort function */
void counting_sort(int a[], int k, int n) {
    int i, j;
    int b[15], c[100] = {0};

    for (j = 0; j < n; j++) {
        c[a[j]] = c[a[j]] + 1;
    }

    for (i = 1; i <= k; i++) {
        c[i] = c[i] + c[i - 1];
    }

    for (j = n - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }

    printf("The Sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main() {
    int n, k = 0, a[15], i;
    printf("Input number of elements: ");
    scanf("%d", &n);
    printf("Input the array elements one by one:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > k) {
            k = a[i];
        }
    }
    counting_sort(a, k, n);
    return 0;
}
