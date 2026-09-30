bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int lim = (m + n) >> 1;

    if (((m + n) & 1) == 0 ||
        grid[0][0] == ')' ||
        grid[m - 1][n - 1] == '(') {
        return false;
    }

    int words = (lim + 64) / 64;

    uint64_t** dp = (uint64_t**)malloc(n * sizeof(uint64_t*));

    for (int j = 0; j < n; j++) {
        dp[j] = (uint64_t*)calloc(words, sizeof(uint64_t));
    }

    dp[0][0] = 1ULL << 1;

    int p = 1;

    for (int j = 1; j < n; j++) {
        p += grid[0][j] == '(' ? 1 : -1;

        if (p < 0 || p > lim) {
            break;
        }

        dp[j][p / 64] |= 1ULL << (p % 64);
    }

    p = 1;

    for (int i = 1; i < m; i++) {
        p += grid[i][0] == '(' ? 1 : -1;
        bool reachable = false;

        for (int w = 0; w < words; w++) {
            if (dp[0][w] != 0) {
                reachable = true;
                break;
            }
        }

        memset(dp[0], 0, words * sizeof(uint64_t));

        if (reachable && p >= 0 && p <= lim) {
            dp[0][p / 64] |= 1ULL << (p % 64);
        }

        for (int j = 1; j < n; j++) {
            for (int w = 0; w < words; w++) {
                dp[j][w] |= dp[j - 1][w];
            }

            if (grid[i][j] == '(') {
                uint64_t carry = 0;

                for (int w = 0; w < words; w++) {
                    uint64_t nextCarry = dp[j][w] >> 63;

                    dp[j][w] = (dp[j][w] << 1) | carry;

                    carry = nextCarry;
                }
            } else {
                uint64_t carry = 0;

                for (int w = words - 1; w >= 0; w--) {
                    uint64_t nextCarry = dp[j][w] & 1ULL;

                    dp[j][w] =
                        (dp[j][w] >> 1) |
                        (carry << 63);

                    carry = nextCarry;
                }
            }

            int validBits = (lim + 1) % 64;

            if (validBits != 0) {
                dp[j][words - 1] &=
                    (1ULL << validBits) - 1;
            }
        }
    }

    bool result = (dp[n - 1][0] & 1ULL) != 0;

    for (int j = 0; j < n; j++) {
        free(dp[j]);
    }

    free(dp);

    return result;
}