int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    int * ret = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int * stk = calloc(temperaturesSize, sizeof(int)); // store indexes
    int pt = -1; // stack pointer (point to the top element, '-1' represent the stack is currently empty)
    
    // starting from the end of the array
    for (int i = temperaturesSize-1; i >= 0; i--){
        while(pt != -1 && temperatures[i] >= temperatures[stk[pt]]) pt--; // pop
        ret[i] = (pt == -1? 0: stk[pt]-i);
        stk[++pt] = i; // push index to stack
    }
    free(stk);
    return ret;
}