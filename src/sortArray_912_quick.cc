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
    void quick_sort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int i = l, j = r, x = nums[l];
            while (i < j)
            {
                while (i < j && nums[j] >= x)
                    j--;
                if (i < j)
                {
                    nums[i] = nums[j];
                    i++;
                }
                while (i < j && nums[i] < x)
                    i++;
                if (i < j)
                {
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = x;
            quick_sort(nums, l, i - 1);
            quick_sort(nums, i + 1, r);
        }
    }

    vector<int> sortArray_912_quick(vector<int> &nums)
    {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
        return nums;
    }
};

TEST(sortArray_912_quick, sortArray_912_quick_1)
{
    Solution s;
    vector<int> in = {5, 2, 3, 1};
    vector<int> ans = {1, 2, 3, 5};
    EXPECT_EQ(s.sortArray_912_quick(in), ans);
}

TEST(sortArray_912_quick, sortArray_912_quick_2)
{
    Solution s;
    vector<int> in = {5, 1, 1, 2, 0, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(s.sortArray_912_quick(in), ans);
}

TEST(sortArray_912_quick, sortArray_912_quick_3)
{
    Solution s;
    vector<int> in = {0};
    vector<int> ans = {0};
    EXPECT_EQ(s.sortArray_912_quick(in), ans);
}

TEST(sortArray_912_quick, sortArray_912_quick_4)
{
    Solution s;
    vector<int> in = {};
    vector<int> ans = {};
    EXPECT_EQ(s.sortArray_912_quick(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}