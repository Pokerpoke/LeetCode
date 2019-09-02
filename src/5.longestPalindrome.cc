#include "headers.h"

class Solution
{
public:
    int expend(string s, int left, int right)
    {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right])
            left--, right++;
        return right - left - 1;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            int len1 = expend(s, i, i);
            int len2 = expend(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + (len) / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

TEST(longestPalindrome, longestPalindrome_1)
{
    Solution s;
    string in = "babad";
    set<string> ans = {"bab", "aba"};
    string a = s.longestPalindrome(in);
    cout << a << endl;
    EXPECT_EQ(ans.count(a), 1);
}

TEST(longestPalindrome, longestPalindrome_2)
{
    Solution s;
    string in = "cbbd";
    set<string> ans = {"bb"};
    string a = s.longestPalindrome(in);
    EXPECT_EQ(ans.count(a), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}