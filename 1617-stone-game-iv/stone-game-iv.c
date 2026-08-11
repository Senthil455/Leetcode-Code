bool winnerSquareGame(int n) {
    bool dp[n + 1];

    for (int i = 0; i <= n; i++) {
        dp[i] = false;
    }

    for (int i = 0; i <= n; i++) {
        if (!dp[i]) {
            for (int j = 1; i + j * j <= n; j++) {
                dp[i + j * j] = true;
            }

            if (dp[n]) {
                return true;
            }
        }
    }

    return false;
}