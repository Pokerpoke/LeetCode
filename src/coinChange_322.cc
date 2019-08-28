/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-09
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int coinChange_322(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

TEST(coinChange_322, coinChange_322_1)
{
    Solution s;
    vector<int> in = {1, 2, 5};
    int amount = 11;
    int ans = 3;
    EXPECT_EQ(s.coinChange_322(in, amount), ans);
}

TEST(coinChange_322, coinChange_322_2)
{
    Solution s;
    vector<int> in = {2};
    int amount = 3;
    int ans = -1;
    EXPECT_EQ(s.coinChange_322(in, amount), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}