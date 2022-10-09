public class BuySellStock {

    public static int maxProfit(int[] prices) {

        if (prices.length == 0)
            return 0;

        int ans = 0;

        int buy_price = prices[0];

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > buy_price) {
                if (ans < (prices[i] - buy_price))
                    ans = prices[i] - buy_price;
            } else {
                buy_price = prices[i];
            }
        }

        return ans;

    }

    public static void main(String args[]) {

        /*
         * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
         * 6-1 = 5.
         * Note that buying on day 2 and selling on day 1 is not allowed because you
         * must buy before you sell.
         */
        int p[] = { 7, 1, 5, 3, 6, 4 };
        System.out.println(maxProfit(p));
    }

}
