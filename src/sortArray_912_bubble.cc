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
    vector<int> sortArray_912_bubble(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
        return nums;
    }
};

TEST(sortArray_912_bubble, sortArray_912_bubble_1)
{
    Solution s;
    vector<int> in = {5, 2, 3, 1};
    vector<int> ans = {1, 2, 3, 5};
    EXPECT_EQ(s.sortArray_912_bubble(in), ans);
}

TEST(sortArray_912_bubble, sortArray_912_bubble_2)
{
    Solution s;
    vector<int> in = {5, 1, 1, 2, 0, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(s.sortArray_912_bubble(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}