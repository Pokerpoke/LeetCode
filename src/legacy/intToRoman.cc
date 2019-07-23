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
    string intToRoman(int num)
    {
        string res;
        int integer[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < 13; i++)
        {
            while (num >= integer[i])
            {
                num -= integer[i];
                res += roman[i];
            }
        }
        return res;
    }
};

TEST(intToRoman, intToRoman)
{
    Solution s;
    EXPECT_EQ(s.intToRoman(3), "III");
    EXPECT_EQ(s.intToRoman(4), "IV");
    EXPECT_EQ(s.intToRoman(9), "IX");
    EXPECT_EQ(s.intToRoman(58), "LVIII");
    EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
