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
 * Last Modified:  2018-12-20
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class WordFilter
{
  public:
    WordFilter(vector<string> words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j <= words[i].size(); j++)
            {
                for (int k = 0; k <= words[i].size(); k++)
                {
                    m[words[i].substr(0, j) + "#" + words[i].substr(words[i].size() - k)] = i;
                }
            }
        }
    }
    int f(string prefix, string suffix)
    {
        return m.count(prefix + "#" + suffix) > 0
                   ? m[prefix + "#" + suffix]
                   : -1;
    }

  private:
    unordered_map<string, int> m;
};

TEST(WordFilter, WordFilter)
{
    vector<string> in{"apple"};
    WordFilter s(in);
    EXPECT_EQ(s.f("a", "e"), 0);
    EXPECT_EQ(s.f("b", ""), -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}