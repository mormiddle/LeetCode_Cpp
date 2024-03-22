// 解决问题：买卖股票的最佳时机
// 思路：暴力解法，遍历所有可能的买卖组合，找出最大利润
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 思想2：动态规划，遍历一次数组，找出最小的买入价格，然后计算每一天的利润，找出最大利润
// 思想2解析：比如数组 10 11 12 13 9 8 7 14 15，一开始遍历，最小买入价格是10，后面的数值只要比10大，那么最大利润一定是后面的数减去10
// 但是如果出现比10小的数，那么最大的利润以及由这个数（9）前面的数决定了，所以可以放心的将最小买入价格设置为9，计算相对于9而言的最大利润

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int tmpmax = 0;
            for (int j = i + 1; j < n; j++)
            {
                int tmp = prices[j] - prices[i];
                if (tmp > tmpmax)
                    tmpmax = tmp;
            }

            if (tmpmax > max)
                max = tmpmax;
        }

        return max;
    }

    int maxProfit2(std::vector<int> &prices)
    {
        int maxProfit = 0;
        int minProfit = 1e9;
        for(int price : prices)
        {
            maxProfit = max(maxProfit, price - minProfit);
            minProfit = min(price, minProfit);
        }

        return maxProfit;
    }
};

int main()
{
    // Test your code here
    std::vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    int maxProfit = s.maxProfit2(prices);
    std::cout << "Max Profit: " << maxProfit << std::endl;

    system("pause");
    return 0;
}