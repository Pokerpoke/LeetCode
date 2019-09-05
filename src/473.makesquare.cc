#include "headers.h"

class Solution
{
public:
    bool DFS(vector<int> &nums, vector<bool> &vis, int i, int a, int cur)
    {
    }
    bool makesquare(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum % 4 != 0)
            return false;
        int target = sum / 4;
        for (auto num : nums)
            if (num > target)
                return false;
        sort(nums.begin(), nums.end());
    }
    return 1;
};

TEST(makesquare, makesquare_1)
{
    Solution s;
    vector<int> in = {1, 1, 2, 2, 2};
    bool ans = true;
    EXPECT_EQ(s.makesquare(in), ans);
}

TEST(makesquare, makesquare_2)
{
    Solution s;
    vector<int> in = {3, 3, 3, 3, 4};
    bool ans = false;
    EXPECT_EQ(s.makesquare(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}