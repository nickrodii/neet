class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int buy = 0;
        int sell = 0;
        int profit = 0;

        for (int l = 0; l < prices.size()-1; l++) {
            for (int r = l+1; r < prices.size(); r++) {
                buy = prices[l];
                sell = prices[r];
                if (sell - buy > profit) profit = sell - buy;
            }
        }

        return profit;
    }
};
