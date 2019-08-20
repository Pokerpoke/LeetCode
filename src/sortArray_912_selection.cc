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
    vector<int> sortArray_912_selection(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < n; j++)
                if (nums[j] < nums[min_index])
                    min_index = j;
            if (min_index != i)
                swap(nums[i], nums[min_index]);
        }
        return nums;
    }
};

TEST(sortArray_912_selection, sortArray_912_selection_1)
{
    Solution s;
    vector<int> in = {5, 2, 3, 1};
    vector<int> ans = {1, 2, 3, 5};
    EXPECT_EQ(s.sortArray_912_selection(in), ans);
}

TEST(sortArray_912_selection, sortArray_912_selection_2)
{
    Solution s;
    vector<int> in = {5, 1, 1, 2, 0, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(s.sortArray_912_selection(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}