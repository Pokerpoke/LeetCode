#include "headers.h"

class Solution
{
public:
    int isValid(vector<int> &nums)
    {
        return 1;
    }
};

TEST(isValid, isValid_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.isValid(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}