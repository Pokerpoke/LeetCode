/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-03-15
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#include "headers.h"

class Solution
{
public:
    pair<int, int> expand_around_center(const string &s, int left, int right)
    {
        while (left >= 0 && right <= s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = expand_around_center(s, i, i);
            auto [left2, right2] = expand_around_center(s, i, i + 1);

            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }

            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

TEST(longestPalindrome, longestPalindrome_1)
{
    Solution s;
    string in = "babad";
    EXPECT_EQ(s.longestPalindrome(in), "bab");
}

TEST(longestPalindrome, longestPalindrome_2)
{
    Solution s;
    string in = "cbbd";
    EXPECT_EQ(s.longestPalindrome(in), "bb");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}