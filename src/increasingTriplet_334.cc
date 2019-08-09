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
 * Last Modified:  2019-08-09
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool increasingTriplet_334(vector<int> &nums)
    {
        int one = INT_MAX, two = INT_MAX;
        for (auto num : nums)
        {
            if (num <= one)
                one = num;
            else if (num <= two)
                two = num;
            else
                return true;
        }
        return false;
    }
};

TEST(increasingTriplet_334, increasingTriplet_334_1)
{
    Solution s;
    vector<int> in = {1, 2, 3, 4, 5};
    bool ans = true;
    EXPECT_EQ(s.increasingTriplet_334(in), ans);
}

TEST(increasingTriplet_334, increasingTriplet_334_2)
{
    Solution s;
    vector<int> in = {5, 4, 3, 2, 1};
    bool ans = false;
    EXPECT_EQ(s.increasingTriplet_334(in), ans);
}

TEST(increasingTriplet_334, increasingTriplet_334_3)
{
    Solution s;
    vector<int> in = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    bool ans = false;
    EXPECT_EQ(s.increasingTriplet_334(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}