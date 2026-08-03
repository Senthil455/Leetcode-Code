int calculateArea(int height, int width) {
    return height * width;
}

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int stackSize = 0;

    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int currentHeight = (i == heightsSize) ? 0 : heights[i];
        while (stackSize > 0 && currentHeight < heights[stack[stackSize - 1]]) {
            int poppedIndex = stack[--stackSize];
            int poppedHeight = heights[poppedIndex];
            int width = (stackSize == 0) ? i : i - stack[stackSize - 1] - 1;

            maxArea = fmax(maxArea, calculateArea(poppedHeight, width));
        }
        stack[stackSize++] = i;
    }

    free(stack);

    return maxArea;
}