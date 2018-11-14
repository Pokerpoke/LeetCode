/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-11-14
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MAX;
        int max_profit = 0;
        for (auto i : prices)
        {
            buy = min(buy, i);
            max_profit = max(max_profit, i - buy);
        }
        return max_profit;
    }
};

TEST(maxProfit, maxProfit1)
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution s;
    EXPECT_EQ(s.maxProfit(prices), 5);
}
TEST(maxProfit, maxProfit2)
{
    vector<int> prices{7, 6, 4, 3, 1};
    Solution s;
    EXPECT_EQ(s.maxProfit(prices), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}