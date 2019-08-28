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
 * Last Modified:  2019-08-24
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool isPowerOfTwo_231(int n)
    {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

TEST(isPowerOfTwo_231, isPowerOfTwo_231_1)
{
    Solution s;
    int in = 1;
    bool ans = true;
    EXPECT_EQ(s.isPowerOfTwo_231(in), ans);
}

TEST(isPowerOfTwo_231, isPowerOfTwo_231_2)
{
    Solution s;
    int in = 16;
    bool ans = true;
    EXPECT_EQ(s.isPowerOfTwo_231(in), ans);
}

TEST(isPowerOfTwo_231, isPowerOfTwo_231_3)
{
    Solution s;
    int in = 218;
    bool ans = false;
    EXPECT_EQ(s.isPowerOfTwo_231(in), ans);
}

TEST(isPowerOfTwo_231, isPowerOfTwo_231_4)
{
    Solution s;
    int in = 0;
    bool ans = false;
    EXPECT_EQ(s.isPowerOfTwo_231(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}