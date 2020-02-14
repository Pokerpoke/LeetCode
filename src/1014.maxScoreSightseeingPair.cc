#include "headers.h"

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &A)
    {
        int res = -1;
        int pre_max = A[0] + 0;
        for (int i = 1; i < A.size(); i++)
        {
            res = max(res, pre_max + A[i] - i);
            pre_max = max(pre_max, A[i] + i);
        }
        return res;
    }
};

TEST(maxScoreSightseeingPair, maxScoreSightseeingPair_1)
{
    Solution s;
    vector<int> in = {8, 1, 5, 2, 6};
    int ans = 11;
    EXPECT_EQ(s.maxScoreSightseeingPair(in), ans);
}

TEST(maxScoreSightseeingPair, maxScoreSightseeingPair_2)
{
    Solution s;
    vector<int> in = {1, 3, 5};
    int ans = 7;
    EXPECT_EQ(s.maxScoreSightseeingPair(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}