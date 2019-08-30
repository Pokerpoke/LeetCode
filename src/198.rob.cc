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
 * Last Modified:  2019-08-02
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};

TEST(rob, rob_1)
{
    Solution s;
    vector<int> in = {1, 2, 3, 1};
    EXPECT_EQ(s.rob(in), 4);
}

TEST(rob, rob_2)
{
    Solution s;
    vector<int> in = {2, 7, 9, 3, 1};
    EXPECT_EQ(s.rob(in), 12);
}

TEST(rob, rob_3)
{
    Solution s;
    vector<int> in = {2, 1, 1, 2};
    EXPECT_EQ(s.rob(in), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}