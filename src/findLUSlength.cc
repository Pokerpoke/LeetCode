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
 * Last Modified:  2019-05-22
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a.size() != b.size())
            return max(a.size(), b.size());
        int j = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[j])
                return max(a.size(), b.size());
            j++;
        }
        return -1;
    }
};

TEST(findLUSlength, findLUSlength_1)
{
    Solution s;
    string a("aba");
    string b("cdc");
    EXPECT_EQ(s.findLUSlength(a, b), 3);
}

TEST(findLUSlength, findLUSlength_2)
{
    Solution s;
    string a("aaa");
    string b("aaa");
    EXPECT_EQ(s.findLUSlength(a, b), -1);
}

TEST(findLUSlength, findLUSlength_3)
{
    Solution s;
    string a("horbxeemlgqpqbujbdagizcfairalg");
    string b("iwvtgyojrfhyzgyzeikqagpfjoaeen");
    EXPECT_EQ(s.findLUSlength(a, b), 30);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}