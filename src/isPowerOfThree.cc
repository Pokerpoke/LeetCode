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
    bool isPowerOfThree(int n)
    {
        if (n > 0 && ((int)pow(3, 19)) % n == 0)
            return true;
        return false;
    }
};

TEST(isPowerOfThree, isPowerOfThree)
{
    Solution s;
    EXPECT_TRUE(s.isPowerOfThree(3));
    EXPECT_TRUE(s.isPowerOfThree(9));
    EXPECT_FALSE(s.isPowerOfThree(0));
    EXPECT_FALSE(s.isPowerOfThree(45));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    Solution s;

    return RUN_ALL_TESTS();
}
