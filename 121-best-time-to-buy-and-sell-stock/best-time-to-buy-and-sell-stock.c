int maxProfit(int* prices, int pricesSize) {
    int min = prices[0];
    int out = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i] < min)
            min = prices[i];
        int profit = prices[i] - min;
        if(profit > out)
            out = profit;
    }
    return out;
}