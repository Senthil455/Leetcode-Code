int candy(int* ratings, int N) 
{
    int candies[N];

    for (int i=0; i < N; i++) {
        candies[i] = 1;
    }

    // adress left neighbour discrepancy
    for (int i=1; i < N; i++) {
        if (ratings[i-1] < ratings[i]) {
            candies[i] = 1 + candies[i-1];
        }
    }
    
    // adress right neighbour discrepancy
    for (int i=N-2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
            candies[i] = 1 + candies[i+1];
        }
    }

    int total = 0;
    for (int i=0; i < N; i++) {
        total += candies[i];
    }

    return total;
}