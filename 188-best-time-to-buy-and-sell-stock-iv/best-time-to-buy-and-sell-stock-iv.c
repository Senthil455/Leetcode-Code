int max(int a, int b) { return  a > b ? a : b; } 

int memo[1000][200];

int maxProfitR(int *prices, int *actions, int pLen, int aLen, int i, int j) {
    if (i == pLen || j == aLen) return 0; // nothing to do
    if (memo[i][j] != -1) { return memo[i][j]; }
    memo[i][j] = max(
        maxProfitR(prices, actions, pLen, aLen, i + 1, j), // do nothing
        actions[j] * prices[i] + maxProfitR(prices, actions, pLen, aLen, i + 1, j + 1) // act
    );
    return memo[i][j];
}

int maxProfit(int k, int* prices, int pricesSize) {
    int actions[2 * k]; // 2 * k actions: k x buy + k * sell
    actions[0] = -1; // buy = -1, sell = 1
    for (int i = 1; i < 2 * k; ++i) actions[i] = -1 * actions[i - 1]; // init actions
    memset(memo, -1, sizeof(memo)); // init memo
    return maxProfitR(prices, actions, pricesSize, 2 * k, 0, 0);
}