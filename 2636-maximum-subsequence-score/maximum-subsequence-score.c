#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)
#define PARENT(i) (i > 0 ? (((i) - 1) / 2) : 0)

// Implementation of a priority queue using a min-heap.
typedef struct {
    int *arr;
    int capacity; // number of memory allocated for elements
    int size; // number of elements
} Min_heap;

void heapify(Min_heap *heap, int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int min_i = i;

    if (l < heap->size && heap->arr[l] < heap->arr[min_i]) {
        min_i = l;
    }
    if (r < heap->size && heap->arr[r] < heap->arr[min_i]) {
        min_i = r;
    }

    if (min_i != i) {
        int temp = heap->arr[min_i];
        heap->arr[min_i] = heap->arr[i];
        heap->arr[i] = temp;

        heapify(heap, min_i);
    }
}

void build_heap(Min_heap *heap) {
    for (int i = PARENT(heap->size - 1); i >= 0; --i) {
        heapify(heap, i);
    }
}

int insert(Min_heap *heap, int elem) {
    if (heap->size == heap->capacity) {
        return 1;
    }

    heap->arr[heap->size] = elem;
    heap->size++;

    int i = heap->size - 1;

    while (i > 0) {
        i = PARENT(i);
        heapify(heap, i);
    }

    return 0;
}

int extract_min(Min_heap *heap, int *result) {
    if (heap->size == 0) {
        return 1;
    }

    *result = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return 0;
}

int min_heap_init(Min_heap *heap, int capacity, int *inits, int n) {
    heap->arr = malloc(capacity * sizeof(int));

    if (heap->arr == NULL) {
        return 1;
    }

    heap->size = 0;
    heap->capacity = capacity;

    if (n > 0) {
        int i = 0;
        for (; i < n && i < capacity; ++i) {
            heap->arr[i] = inits[i];
        }
        heap->size = i;

        build_heap(heap);
    }

    return 0;
}

int min_heap_destroy(Min_heap *heap) {
    if (heap->arr == NULL) {
        return 1;
    }

    free(heap->arr);

    return 0;
}

long long min_heap_sum(Min_heap *heap) {
    long long result = 0;

    for (int i = 0; i < heap->size; ++i) {
        result += heap->arr[i];
    }

    return result;
}

// Implementation of the algorithm.
typedef struct {
    int first;
    int second;
} pair;

int cmp(const void *lhs, const void *rhs) {
    const pair *lhs_pair = (const pair *) lhs;
    const pair *rhs_pair = (const pair *) rhs;

    if (lhs_pair->second < rhs_pair->second) {
        return 1;
    }
    else if (lhs_pair->second > rhs_pair->second) {
        return -1;
    }
    else {
        return 0;
    }
}

// nums1Size == nums2Size
long long maxScore(int *nums1, int nums1Size, int *nums2, int nums2Size, int k){
    // Create a sorted pair array.
    pair *pairs = malloc(nums1Size * sizeof(pair));

    if (pairs == NULL) {
        fprintf(stderr, "Failed to allocate memory for pairs.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nums1Size; ++i) {
        pairs[i].first = nums1[i];
        pairs[i].second = nums2[i];
    }

    qsort(pairs, nums1Size, sizeof(pair), cmp);

    // Create a priority queue and gradually expand a set of indices used
    // for computing max_score.
    int *initializer = malloc(k * sizeof(pair));

    if (initializer == NULL) {
        fprintf(stderr, "Failed to allocate memory for initializer.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < k; ++i) {
        initializer[i] = pairs[i].first;
    }

    Min_heap prio_queue;
    min_heap_init(&prio_queue, k, initializer, k);

    long long cur_sum = min_heap_sum(&prio_queue);
    long long max_score = pairs[k - 1].second * cur_sum;
    
    // At this point we have an array of pairs that are sorted
    // in decreasing order according to the second member.
    for (int i = k; i < nums1Size; ++i) {
        int result = 0;
        extract_min(&prio_queue, &result);
        cur_sum -= result;
        cur_sum += pairs[i].first;
        insert(&prio_queue, pairs[i].first);

        long long new_score = pairs[i].second * cur_sum;

        if (new_score > max_score) {
            max_score = new_score;
        }
    }


    free(pairs);
    free(initializer);
    min_heap_destroy(&prio_queue);

    return max_score;
}