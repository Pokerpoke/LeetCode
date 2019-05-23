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
 * Last Modified:  2019-05-23
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() == 0)
            return res;
        // if (nums.size() == 1)
        //     return vector<string> to_string(nums[0]);
        int start = nums[0];
        int end = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (long(nums[i]) - long(nums[i - 1]) == 1)
                end = nums[i];
            else
            {
                string s;
                if (start == end)
                    s = to_string(start);
                else
                    s = to_string(start) + "->" + to_string(end);
                res.push_back(s);
                start = nums[i];
                end = nums[i];
            }
        }
        string s;
        if (start == end)
            s = to_string(start);
        else
            s = to_string(start) + "->" + to_string(end);
        res.push_back(s);
        return res;
    }
};

TEST(summaryRanges, summaryRanges_1)
{
    Solution s;
    vector<int> v{0, 1, 2, 4, 5, 7};
    vector<string> res{"0->2", "4->5", "7"};
    EXPECT_EQ(s.summaryRanges(v), res);
}

TEST(summaryRanges, summaryRanges_2)
{
    Solution s;
    vector<int> v{0, 2, 3, 4, 6, 8, 9};
    vector<string> res{"0", "2->4", "6", "8->9"};
    EXPECT_EQ(s.summaryRanges(v), res);
}

TEST(summaryRanges, summaryRanges_3)
{
    Solution s;
    vector<int> v{-2147483648, -2147483647, 2147483647};
    vector<string> res{"-2147483648->-2147483647", "2147483647"};
    EXPECT_EQ(s.summaryRanges(v), res);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}