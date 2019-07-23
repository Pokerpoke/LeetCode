/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (pokerpoke@qq.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-10
 * Modified By:    姜阳 (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    int hanmingDistance(int x, int y)
    {
        int res = 0;
        while (x != 0 || y != 0)
        {
            res += (x & 0x01) ^ (y & 0x01);
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};

TEST(hanmingDistance, hanmingDistance)
{
    Solution s;
    EXPECT_EQ(s.hanmingDistance(1, 4), 2);
    EXPECT_EQ(s.hanmingDistance(3, 1), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
