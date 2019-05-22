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
    int minFallingPathSum(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 2, 0));
        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = INT_MAX;
            dp[i][n + 1] = INT_MAX;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = A[i - 1][j - 1] + min(dp[i - 1][j - 1],
                                                 min(dp[i - 1][j], dp[i - 1][j + 1]));
            }
        }
        sort(dp[m].begin(), dp[m].end());
        return dp[m][0];
    }
};

TEST(minFallingPathSum, minFallingPathSum_1)
{
    Solution s;
    vector<vector<int>> v{{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};
    EXPECT_EQ(s.minFallingPathSum(v), 12);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}