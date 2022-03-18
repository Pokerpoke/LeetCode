/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-03-18
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#include "headers.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp;

        dp.push_back(1);
        dp.push_back(2);

        for (int i = 2; i < n; i++)
        {
            dp.push_back(dp.at(i - 1) + dp.at(i - 2));
        }

        return dp.at(n - 1);
    }
};

TEST(climbStairs, climbStairs_1)
{
    Solution s;
    int in = 2;
    int ans = 2;
    EXPECT_EQ(s.climbStairs(in), ans);
}

TEST(climbStairs, climbStairs_2)
{
    Solution s;
    int in = 3;
    int ans = 3;
    EXPECT_EQ(s.climbStairs(in), ans);
}

TEST(climbStairs, climbStairs_3)
{
    Solution s;
    int in = 1;
    int ans = 1;
    EXPECT_EQ(s.climbStairs(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}