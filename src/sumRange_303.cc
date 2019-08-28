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
    bool sumRange_303(string s)
    {
        return true;
    }
};

class NumArray
{
public:
    vector<int> sums;
    NumArray(vector<int> &nums)
    {
        sums.push_back(0);
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    int sumRange(int i, int j)
    {
        return sums[j + 1] - sums[i];
    }
};

TEST(sumRange_303, sumRange_303_1)
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    NumArray *obj = new NumArray(nums);
    for (int i = 0; i < 1000; i++)
    {
        EXPECT_EQ(obj->sumRange(0, 9), 55);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}