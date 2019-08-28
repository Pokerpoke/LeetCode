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
 * Last Modified:  2019-08-20
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int minCostClimbingStairs_746(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

TEST(minCostClimbingStairs_746, minCostClimbingStairs_746_1)
{
    Solution s;
    vector<int> in = {10, 15, 20};
    int ans = 15;
    EXPECT_EQ(s.minCostClimbingStairs_746(in), ans);
}

TEST(minCostClimbingStairs_746, minCostClimbingStairs_746_2)
{
    Solution s;
    vector<int> in = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int ans = 6;
    EXPECT_EQ(s.minCostClimbingStairs_746(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}