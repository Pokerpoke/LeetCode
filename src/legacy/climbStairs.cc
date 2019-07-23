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
 * Last Modified:  2018-09-18
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    int climbStairs(int n)
    {
        int ways[] = {1, 1};
        for (int i = 1; i < n; i++)
        {
            int temp = ways[1];
            ways[1] += ways[0];
            ways[0] = temp;
        }
        return ways[1];
    }
};

TEST(climbStairs, climbStairs)
{
    Solution s;
    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}