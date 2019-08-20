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
    vector<int> sortArray_912_insertion(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i];
            int j = i;
            for (; j > 0; j--)
            {
                if (nums[j - 1] > temp)
                    nums[j] = nums[j - 1];
                else
                    break;
            }
            nums[j] = temp;
        }
        return nums;
    }
};

TEST(sortArray_912_insertion, sortArray_912_insertion_1)
{
    Solution s;
    vector<int> in = {5, 2, 3, 1};
    vector<int> ans = {1, 2, 3, 5};
    EXPECT_EQ(s.sortArray_912_insertion(in), ans);
}

TEST(sortArray_912_insertion, sortArray_912_insertion_2)
{
    Solution s;
    vector<int> in = {5, 1, 1, 2, 0, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 5};
    EXPECT_EQ(s.sortArray_912_insertion(in), ans);
}

TEST(sortArray_912_insertion, sortArray_912_insertion_3)
{
    Solution s;
    vector<int> in = {0};
    vector<int> ans = {0};
    EXPECT_EQ(s.sortArray_912_insertion(in), ans);
}

TEST(sortArray_912_insertion, sortArray_912_insertion_4)
{
    Solution s;
    vector<int> in = {};
    vector<int> ans = {};
    EXPECT_EQ(s.sortArray_912_insertion(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}