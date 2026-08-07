static const int PRIME[4] = {2, 3, 5, 7};

/* digit → exponent vector of (2,3,5,7) */
static const int DIGIT_FAC[10][4] = {
    {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
    {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
};

/* ---------- helpers on the four-prime exponent vectors ---------- */
static bool covers(const int need[4], const int have[4])
{
    for (int i = 0; i < 4; ++i)
        if (have[i] < need[i]) return false;
    return true;
}

/* pack a prime-exponent vector into the **fewest / lexicographically first**
   multiset of digits 2…9, stored in mult[10] (index = digit)            */
static void pack(const int cnt[4], int mult[10])
{
    memset(mult, 0, 10 * sizeof(int));
    int c2 = cnt[0], c3 = cnt[1], c5 = cnt[2], c7 = cnt[3];

    /* 8 = 2³, 9 = 3², 4 = 2² minimise length                        */
    mult[8] = c2 / 3;           c2 %= 3;
    mult[9] = c3 / 2;           c3 %= 2;
    mult[4] = c2 / 2;           c2 %= 2;

    /* convert 2 + 3 → 6 whenever it shrinks length */
    if (c2 == 1 && c3 == 1) { mult[6]++; c2 = c3 = 0; }

    /* special tweak: 4 + 3 → 6 + 2 keeps length but gives smaller number */
    if (c3 == 1 && mult[4] == 1) { mult[4]--; mult[6]++; c3 = 0; c2++; }

    mult[2] = c2;  mult[3] = c3;  mult[5] = c5;  mult[7] = c7;
}

/* sum of multiset sizes (digits ≠ 1) */
static int mult_len(const int mult[10])
{
    int s = 0;
    for (int d = 2; d <= 9; ++d) s += mult[d];
    return s;
}

/* append multiset (digits 2…9) to buffer, returns new cursor */
static int append_mult(char *buf, int pos, const int mult[10])
{
    for (int d = 2; d <= 9; ++d)
        for (int k = 0; k < mult[d]; ++k) buf[pos++] = '0' + d;
    return pos;
}
/* ------------------------------------------------------------------ */

/* main driver – returns **heap-allocated** answer string */
char *smallestNumber(const char *num, long long t)
{
    int need[4] = {0};                    /* prime exponents of t         */
    for (int p = 0; p < 4; ++p)
        while (t % PRIME[p] == 0) { t /= PRIME[p]; ++need[p]; }
    if (t != 1) {                         /* other prime factor present   */
        char *ans = strdup("-1"); return ans;
    }

    int packed[10];                       /* minimal multiset for t       */
    pack(need, packed);
    int min_len = mult_len(packed);

    int n   = (int)strlen(num);
    int z0  = -1;                         /* first ‘0’ in num, if any     */

    /* prefix prime counts, pref[i] = num[0…i-1] */
    int (*pref)[4] = calloc(n + 1, sizeof *pref);
    for (int i = 0; i < n; ++i) {
        int d = num[i] - '0';
        if (d == 0 && z0 == -1) z0 = i;   /* remember earliest zero       */
        for (int k = 0; k < 4; ++k)
            pref[i + 1][k] = pref[i][k] + DIGIT_FAC[d][k];
    }

    /* if num itself qualifies (no ‘0’ and product covers need) */
    if (z0 == -1 && covers(need, pref[n])) {
        free(pref);
        return strdup(num);
    }
    if (z0 == -1) z0 = n;                 /* treat “no zero” as n         */

    /* ---------- try to stay in same length ---------- */
    for (int i = n - 1; i >= 0; --i) {
        if (i > z0) continue;             /* a preceding zero blocks path */

        int space = n - 1 - i;            /* free slots to the right      */
        for (int bigger = num[i] - '0' + 1; bigger <= 9; ++bigger) {

            int rem[4];
            for (int k = 0; k < 4; ++k) {
                rem[k] = need[k] - pref[i][k] - DIGIT_FAC[bigger][k];
                if (rem[k] < 0) rem[k] = 0;
            }
            int mult[10]; pack(rem, mult);
            int need_slots = mult_len(mult);

            if (need_slots <= space) {    /* feasible suffix found        */
                int ans_len = i + 1 + space;          /* == n             */
                char *ans = malloc(ans_len + 1);

                /* prefix unchanged part */
                memcpy(ans, num, i);      /* up to i-1 inclusive */
                ans[i] = '0' + bigger;

                int pos = i + 1;
                int ones = space - need_slots;
                memset(ans + pos, '1', ones);
                pos += ones;
                pos = append_mult(ans, pos, mult);
                ans[pos] = '\0';

                free(pref);
                return ans;
            }
        }
    }

    /* ---------- need a longer number (could be > n+1) ---------- */
    int target_len = (min_len > n) ? min_len : (n + 1);  /* smallest legal length */
    int ones       = target_len - min_len;               /* ≥ 0 by construction   */

    char *ans = malloc((size_t)target_len + 1);          /* +1 for the '\0'       */
    int pos = 0;
    if (ones) {
        memset(ans, '1', (size_t)ones);                  /* leading 1-padding     */
        pos += ones;
    }
    pos = append_mult(ans, pos, packed);                 /* digits 2…9            */
    ans[target_len] = '\0';

    free(pref);
    return ans;


}