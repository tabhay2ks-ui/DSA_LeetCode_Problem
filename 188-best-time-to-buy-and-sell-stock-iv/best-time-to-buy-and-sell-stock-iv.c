int maxProfit(int k, int* prices, int pricesSize) {
    int * buy = (int *)malloc((k + 1) * sizeof(int));
    int * sell = (int *)malloc((k + 1) * sizeof(int));
    sell[0] = 0;

    for(int i = 1; i <= k; i++){
        buy[i] = INT_MIN;
        sell[i] = 0;
    }
    for(int i = 0; i<pricesSize; i++){
        for(int t = 1; t <= k; t++){
            if(sell[t-1] - prices[i] > buy[t]){
                buy[t] = sell[t-1] - prices[i];
            }
            if(buy[t] + prices[i] > sell[t]){
                sell[t] = buy[t] + prices[i];
            }
        }
    }
    int ans = sell[k];
    free(buy);
    free(sell);
    return ans;
}