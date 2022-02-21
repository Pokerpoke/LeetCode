#include "headers.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> index;

        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            map<int, int>::iterator x = index.find(target - nums[i]);
            if (x == index.end())
            {
                index[nums[i]] = i;
            }
            else
            {
                return {i, x->second};
            }
        }

        return {};
    }
};

TEST(TwoSum, TwoSum_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    vector<int> out = s.twoSum(in, 4);
    vector<int> expect = {2, 0};

    EXPECT_EQ(expect.size(), out.size());

    for (int i = 0; i < expect.size(); i++)
    {
        EXPECT_EQ(expect[i], out[i]);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}