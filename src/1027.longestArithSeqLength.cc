#include "headers.h"

class Solution
{
public:
    int longestArithSeqLength(vector<int> &A)
    {
        int n = A.size();
        if (n == 0)
            return 0;
        vector<unordered_map<int, int>> dp(n);
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int gap = A[i] - A[j];
                if (dp[j].count(gap) > 0)
                    dp[i][gap] = dp[j][gap] + 1;
                else
                    dp[i][gap] = 2;
                res = max(res, dp[i][gap]);
            }
        }
        return res;
    }
};

TEST(longestArithSeqLength, longestArithSeqLength_1)
{
    Solution s;
    vector<int> in = {3, 6, 9, 12};
    int ans = 4;
    EXPECT_EQ(s.longestArithSeqLength(in), ans);
}

TEST(longestArithSeqLength, longestArithSeqLength_2)
{
    Solution s;
    vector<int> in = {9, 4, 7, 2, 10};
    int ans = 3;
    EXPECT_EQ(s.longestArithSeqLength(in), ans);
}

TEST(longestArithSeqLength, longestArithSeqLength_3)
{
    Solution s;
    vector<int> in = {20, 1, 15, 3, 10, 5, 8};
    int ans = 4;
    EXPECT_EQ(s.longestArithSeqLength(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}