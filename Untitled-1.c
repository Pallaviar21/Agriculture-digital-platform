#include <stdio.h>


void merge(int *a, int low, int mid, int high) {
    int resarr[25];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            resarr[k++] = a[i++];
        } else {
            resarr[k++] = a[j++];
        }
    }

    while (i <= mid) {
        resarr[k++] = a[i++];
    }

    while (j <= high) {
        resarr[k++] = a[j++];
    }
  
    for (int m = low; m <= high; m++) {
        a[m] = resarr[m];
    }
}

void sort(int *a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        sort(a, low, mid);
        sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n, i;
    int a[25];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
