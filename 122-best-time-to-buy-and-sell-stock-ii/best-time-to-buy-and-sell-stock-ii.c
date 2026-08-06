int maxProfit(int* prices, int pricesSize) {
    int bp=prices[0];
    int pr = 0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]>bp){
            pr+=prices[i]-bp;
        }
        bp = prices[i];
    }
    return pr; 
}