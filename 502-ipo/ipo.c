#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int p, int mid, int r, int b[]) {
    int n1 = mid - p + 1;
    int n2 = r - mid;
    int l1[n1], l2[n1], m1[n2], m2[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) {
        l1[i] = a[p + i];
        l2[i] = b[p + i];
    }
    for (j = 0; j < n2; j++) {
        m1[j] = a[mid + 1 + j];
        m2[j] = b[mid + 1 + j];
    }

    i = 0; j = 0; k = p;
    while (i < n1 && j < n2) {
        if (l1[i] <= m1[j]) {
            a[k] = l1[i];
            b[k] = l2[i];
            i++;
        } else {
            a[k] = m1[j];
            b[k] = m2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = l1[i];
        b[k] = l2[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = m1[j];
        b[k] = m2[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int p, int r, int b[]) {
    if (p < r) {
        int mid = (p + r) / 2;
        mergesort(a, p, mid, b);
        mergesort(a, mid + 1, r, b);
        merge(a, p, mid, r, b);
    }
}

void push(int* heap, int* heapSize, int value) {
    heap[(*heapSize)++] = value;
    int i = *heapSize - 1;
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int pop(int* heap, int* heapSize) {
    int result = heap[0];
    heap[0] = heap[--(*heapSize)];
    int i = 0;
    while (2 * i + 1 < *heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxChild = (right < *heapSize && heap[right] > heap[left]) ? right : left;
        if (heap[i] >= heap[maxChild]) break;
        int temp = heap[i];
        heap[i] = heap[maxChild];
        heap[maxChild] = temp;
        i = maxChild;
    }
    return result;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    int* projectsCapital = (int*)malloc(capitalSize * sizeof(int));
    int* projectsProfit = (int*)malloc(profitsSize * sizeof(int));
    for (int i = 0; i < capitalSize; i++) {
        projectsCapital[i] = capital[i];
        projectsProfit[i] = profits[i];
    }

    mergesort(projectsCapital, 0, capitalSize - 1, projectsProfit);
    int* heap = (int*)malloc(profitsSize * sizeof(int));
    int heapSize = 0;
    int totalProfit = w;
    int j = 0;

    for (int i = 0; i < k; i++) {
        while (j < capitalSize && projectsCapital[j] <= totalProfit) {
            push(heap, &heapSize, projectsProfit[j]);
            j++;
        }

        if (heapSize == 0) break;

        totalProfit += pop(heap, &heapSize);
    }

    free(projectsCapital);
    free(projectsProfit);
    free(heap);

    return totalProfit;
}