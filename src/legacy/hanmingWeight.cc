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
    int hanmingWeight(uint32_t n)
    {
        int res = 0;
        while (n != 0)
        {
            if (n & 0x01 == 1)
                res++;
            n = n >> 1;
        }
        return res;
    }
};

TEST(hanmingWeight, hanmingWeight)
{
    Solution s;
    EXPECT_EQ(s.hanmingWeight(11), 3);
    EXPECT_EQ(s.hanmingWeight(128), 1);
    // EXPECT_EQ(s.hanmingWeight(9), "IX");
    // EXPECT_EQ(s.hanmingWeight(58), "LVIII");
    // EXPECT_EQ(s.hanmingWeight(1994), "MCMXCIV");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
