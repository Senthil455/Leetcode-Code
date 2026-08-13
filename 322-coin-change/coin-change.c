int trav(int* coins, int size, int amount, int min, int* dp) {
    if (amount == 0) {
        dp[amount] = 0;
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    if (amount > 0) {

        for (int i = 0; i < size; i++) {
            int a;
            if (amount-coins[i]>=0&&dp[amount-coins[i]] != -2) {
                a = dp[amount-coins[i]];
            } else {

                a=trav(coins, size, amount - coins[i], INT_MAX, dp);
            }
            if (a != -1) {

                if (min > a + 1) {
                    min = a + 1;
                }
            }
        }
        dp[amount] = (min == INT_MAX) ? -1 : min;
        if (min == INT_MAX) {
            return -1;
        }
        return min;
    }
    return 0;
}
int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i < (amount + 1); i++) {
        dp[i] = -2;
    }
    return trav(coins, coinsSize, amount, INT_MAX, dp);
}