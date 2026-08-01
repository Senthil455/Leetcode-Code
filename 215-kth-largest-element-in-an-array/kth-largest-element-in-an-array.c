struct MinHeap {
    int *arr;
    int capacity;
    int size;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap* heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap->arr[index] < heap->arr[parentIndex]) {
            swap(&heap->arr[index], &heap->arr[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void heapifyDown(struct MinHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(struct MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }

    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int findKthLargest(int* nums, int numsSize, int k) {
    struct MinHeap* minHeap = createMinHeap(k);

    for (int i = 0; i < numsSize; i++) {
        if (minHeap->size < k) {
            insert(minHeap, nums[i]);
        } else if (nums[i] > minHeap->arr[0]) {
            minHeap->arr[0] = nums[i];
            heapifyDown(minHeap, 0);
        }
    }

    int kthLargest = minHeap->arr[0];

    free(minHeap->arr);
    free(minHeap);

    return kthLargest;
}

//O(n^2)
    // for(int i = 0; i<numsSize; i++){
    //     for(int j=0; j<numsSize-i-1; j++){
    //         if(nums[j]<nums[j+1]){
    //             int temp = nums[j];
    //             nums[j] = nums[j+1];
    //             nums[j+1] = temp;
    //         }
    //     }
    // }
    // return nums[k-1];

//O(n*k)
    // int i, max = INT_MIN, index;
    // while(k--){ 
    //     index = -1;
    //     max = INT_MIN;
    //     i = 0;
    //     while(i<numsSize){
    //         if(nums[i] > max){
    //             index = i;
    //             max = nums[i];
    //         }
    //         i++;
    //     }
    //     if(index!=-1)
    //     nums[index] = INT_MIN;
    // }
    // return max;