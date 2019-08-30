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
 * Last Modified:  2019-08-30
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n + 1), dp2(n + 1);
        for (int i = 2; i < n + 1; i++)
        {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 2]);
        }
        return max(dp1[n], dp2[n]);
    }
};

TEST(rob, rob_1)
{
    Solution s;
    vector<int> in{2, 3, 2};
    EXPECT_EQ(s.rob(in), 3);
}

TEST(rob, rob_2)
{
    Solution s;
    vector<int> in{1, 2, 3, 1};
    EXPECT_EQ(s.rob(in), 4);
}

TEST(rob, rob_3)
{
    Solution s;
    vector<int> in;
    EXPECT_EQ(s.rob(in), 0);
}

TEST(rob, rob_4)
{
    Solution s;
    vector<int> in{1};
    EXPECT_EQ(s.rob(in), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}