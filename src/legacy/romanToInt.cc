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
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> roman{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((i + 1) > s.size() || roman[s[i + 1]] <= roman[s[i]])
                res += roman[s[i]];
            else
                res -= roman[s[i]];
        }
        return res;
    }
};

TEST(romanToInt, romanToInt)
{
    Solution s;
    EXPECT_EQ(s.romanToInt("III"), 3);
    EXPECT_EQ(s.romanToInt("IV"), 4);
    EXPECT_EQ(s.romanToInt("IX"), 9);
    EXPECT_EQ(s.romanToInt("LVIII"), 58);
    EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
