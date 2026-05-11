class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {

            // cập nhật giá nhỏ nhất
            minPrice = min(minPrice, price);

            // tính lợi nhuận nếu bán hôm nay
            int profit = price - minPrice;

            // cập nhật lợi nhuận lớn nhất
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};