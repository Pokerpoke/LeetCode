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
 * Last Modified:  2018-09-12
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    bool isValid(string s)
    {
        return true;
    }
};

TEST(isValid, isValid)
{
    Solution s;
    EXPECT_TRUE(s.isValid(""));
    EXPECT_TRUE(s.isValid("()"));
    EXPECT_FALSE(s.isValid(")"));
    EXPECT_TRUE(s.isValid("[]"));
    EXPECT_TRUE(s.isValid("()[]{}"));
    EXPECT_FALSE(s.isValid("(])"));
    EXPECT_FALSE(s.isValid("([)]"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}