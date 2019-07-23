/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-11-27
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
  public:
    vector<Interval> merge_intervals(vector<Interval> &intervals)
    {
        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.begin() + m + n);
    }
};

TEST(merge_intervals, merge_intervals1)
{
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}