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
 * Last Modified:  2019-08-01
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int maxSubArray(vector<int> nums)
    {
        int sum = 0, n = nums.size(), ans = INT_MIN;

        for (auto it : nums)
        {
            if (sum < 0)
                sum = 0;
            sum += it;
            ans = max(ans, sum);
        }

        return ans;
    }
};

TEST(maxSubArray, maxSubArray_1)
{
    Solution s;
    vector<int> in = {1, -2, 3, 10, -4, 7, 2, -5};
    EXPECT_EQ(s.maxSubArray(in), 18);
}

TEST(maxSubArray, maxSubArray_2)
{
    Solution s;
    vector<int> in = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(in), 6);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}