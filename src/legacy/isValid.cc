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
 * Last Modified:  2018-09-12
 * Modified By:    姜阳 (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                else if ((s[i] == ')' && st.top() == '(') ||
                         (s[i] == ']' && st.top() == '[') ||
                         (s[i] == '}' && st.top() == '{'))
                    st.pop();
                else
                    break;
            }
        }
        return st.empty();
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