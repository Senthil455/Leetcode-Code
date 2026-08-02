int trap(int* height, int heightSize) {
    int* left = (int*)malloc(sizeof(int) * heightSize);
    int* right = (int*)malloc(sizeof(int) * heightSize);

    int max = -1;
    for (int i = 0; i < heightSize; i++) {
        left[i] = max;
        if (height[i] > max) max = height[i];
    }

    max = -1;
    for (int i = heightSize - 1; i > 0; i--) {
        right[i] = max;
        if (height[i] > max) max = height[i];
    }

    int water = 0;
    for (int i = 1; i < heightSize - 1; i++) {
        int min = left[i] < right[i] ? left[i] : right[i];
        if (min > height[i]) water += min - height[i];
    }

    free(left);
    free(right);
    return water;
}