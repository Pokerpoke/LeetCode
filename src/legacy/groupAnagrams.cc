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
 * Last Modified:  2019-06-24
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
        {
            if (sort_helper())
        }
        return res;
    }
    bool sort_helper(unordered_set<string> str, string str)
    {
        string ordered_str;
        ordered_str = sort(str.begin(), str.end());
        return str.count(ordered_str);
    }
};

TEST(groupAnagrams, groupAnagrams_1)
{
    Solution s;
    vector<string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> out = {{"ate", "eat", "tea"},
                                  {"nat", "tan"},
                                  {"bat"}};
    EXPECT_EQ(s.groupAnagrams(in), out);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}