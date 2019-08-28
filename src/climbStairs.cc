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
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int first = 1, second = 2, third = 3;
        for (int i = 0; i < n - 2; i++)
        {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};

TEST(climbStairs, climbStairs_1)
{
    Solution s;
    EXPECT_EQ(s.climbStairs(2), 2);
}

TEST(climbStairs, climbStairs_2)
{
    Solution s;
    EXPECT_EQ(s.climbStairs(3), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}