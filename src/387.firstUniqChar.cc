#include "headers.h"

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> map;

        for (const auto &it : s)
        {
            map[it]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (map[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

TEST(firstUniqChar, firstUniqChar_1)
{
    Solution s;
    string in = "leetcode";
    int ans = 0;
    EXPECT_EQ(s.firstUniqChar(in), ans);
}

TEST(firstUniqChar, firstUniqChar_2)
{
    Solution s;
    string in = "loveleetcode";
    int ans = 2;
    EXPECT_EQ(s.firstUniqChar(in), ans);
}

TEST(firstUniqChar, firstUniqChar_3)
{
    Solution s;
    string in = "aabb";
    int ans = -1;
    EXPECT_EQ(s.firstUniqChar(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}