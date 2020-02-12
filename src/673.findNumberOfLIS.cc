#include "headers.h"

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;
        vector<int> len(n);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (len[j] >= len[i])
                    {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (len[i] == len[j] + 1)
                        cnt[i] += cnt[j];
                }
            }
        }
        int longest = *max_element(len.begin(), len.end());
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (len[i] == longest)
                res += cnt[i];
        }
        return res;
    }
};

TEST(findNumberOfLIS, findNumberOfLIS_1)
{
    Solution s;
    vector<int> in = {1, 3, 5, 4, 7};
    int ans = 2;
    EXPECT_EQ(s.findNumberOfLIS(in), ans);
}

TEST(findNumberOfLIS, findNumberOfLIS_2)
{
    Solution s;
    vector<int> in = {2, 2, 2, 2, 2};
    int ans = 5;
    EXPECT_EQ(s.findNumberOfLIS(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}