/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-12
 * Modified By:    姜阳 (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        if (n == 0)
            return 0;
        for (auto it : nums)
        {
            sum += it;
        }
        return ((n * (n + 1) / 2) - sum);
    }
};

TEST(missingNumber, missingNumber)
{
    Solution s;
    vector<int> nums{3, 0, 1};
    EXPECT_EQ(s.missingNumber(nums), 2);
    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    EXPECT_EQ(s.missingNumber(nums), 8);
    nums = {0};
    EXPECT_EQ(s.missingNumber(nums), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}