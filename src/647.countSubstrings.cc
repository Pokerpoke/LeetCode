#include "headers.h"

class Solution
{
public:
    int expand(string s, int left, int right)
    {
        int cnt = 0, n = s.size();
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
            cnt++;
        }
        return cnt;
    }

    int countSubstrings(string s)
    {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt1 = expand(s, i, i);
            int cnt2 = expand(s, i, i + 1);
            res += cnt1 + cnt2;
        }
        return res;
    }
};

TEST(countSubstrings, countSubstrings_1)
{
    Solution s;
    string in = "abc";
    int ans = 3;
    EXPECT_EQ(s.countSubstrings(in), ans);
}

TEST(countSubstrings, countSubstrings_2)
{
    Solution s;
    string in = "aaa";
    int ans = 6;
    EXPECT_EQ(s.countSubstrings(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}