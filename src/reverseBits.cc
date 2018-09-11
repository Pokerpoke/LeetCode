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
 * Last Modified:  2018-09-11
 * Modified By:    姜阳 (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            res += (n & 0x01) << (31 - i);
            n >>= 1;
        }
        return res;
    }
};

TEST(reverseBits, reverseBits)
{
    Solution s;
    EXPECT_EQ(s.reverseBits(43261596), 964176192);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
