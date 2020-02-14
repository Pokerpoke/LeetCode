#include "headers.h"

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int x0 = points[0][0];
        int y0 = points[0][1];
        int n = points.size();
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            res += max(abs(x1 - x0), abs(y1 - y0));
            x0 = x1;
            y0 = y1;
        }
        return res;
    }
};

TEST(minTimeToVisitAllPoints, minTimeToVisitAllPoints_1)
{
    Solution s;
    vector<vector<int>> in = {{1, 1},
                              {3, 4},
                              {-1, 0}};
    int ans = 7;
    EXPECT_EQ(s.minTimeToVisitAllPoints(in), ans);
}

TEST(minTimeToVisitAllPoints, minTimeToVisitAllPoints_2)
{
    Solution s;
    vector<vector<int>> in = {{3, 2},
                              {-2, 2}};
    int ans = 5;
    EXPECT_EQ(s.minTimeToVisitAllPoints(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}