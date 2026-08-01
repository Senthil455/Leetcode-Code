int minCostClimbingStairs(int* cost, int costSize) {
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < costSize; i++) {
        int curr = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return (prev1 < prev2 ? prev1 : prev2);
}