typedef struct {
    int top;
    int size;
    int heap[1008];
} SmallestInfiniteSet;

void pushHeap(int *arr, int size, int new) {
    int i = size, tmp, next;
    arr[i] = new;
    while (i > 0) {
        next = (i - 1) / 2;
        if (arr[i] < arr[ next ]) {
            tmp = arr[i];
            arr[i] = arr[ next ];
            arr[ next ] = tmp;
            i = next;
        }
        else {
            return ;
        }
    }
    return ;
}
void popHeap(int *arr, int size) {
    int i = 0, next, end = size - 1, tmp;
    arr[0] = arr[size - 1];
    while (i * 2 + 1 < end) {
        if (i * 2 + 2 < end) {
            next = (arr[i * 2 + 1] < arr[i * 2 + 2]) ? i * 2 + 1 : i * 2 + 2;
            if (arr[i] > arr[next]) {
                tmp = arr[i];
                arr[i] = arr[next];
                arr[next] = tmp;
                i = next;
            }
            else {
                return ;
            }
        }
        else if (i * 2 + 1 < end) {
            next = i * 2 + 1;
            if (arr[i] > arr[next]) {
                tmp = arr[i];
                arr[i] = arr[next];
                arr[next] = tmp;
                i = next;
            }
            else {
                return ;
            }
        }
    }
    return ;
}

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet *obj = (SmallestInfiniteSet *)malloc(sizeof(SmallestInfiniteSet));
    bzero(obj, sizeof(SmallestInfiniteSet));
    obj->top = 1;
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int ans;
    if (obj->size) {
        ans = obj->heap[0];
        popHeap(obj->heap, obj->size);
        obj->size --;
        while (obj->size && obj->heap[0] == ans) {
            popHeap(obj->heap, obj->size);
            obj->size --;
        }
    }
    else {
        ans = obj->top;
        obj->top ++;
    }
    return ans;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if (obj->top <= num) {
        return ;
    }
    else {
        pushHeap(obj->heap, obj->size, num);
        obj->size ++;
    }
    return ;
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
    return;
}