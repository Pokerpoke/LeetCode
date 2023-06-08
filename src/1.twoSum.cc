#include "headers.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            auto num     = nums.at(i);
            auto to_find = target - num;
            // auto find_res = find(table.begin(), table.end(), to_find);
            auto find_res = table.find(to_find);
            if (find_res != table.end())
            {
                return {find_res->second, i};
            }
            table.insert({num, i});
        }
        return {};
    }
};

TEST(twoSum, twoSum_1)
{
    Solution s;
    vector<int> in  = {2, 7, 11, 15};
    int target      = 9;
    vector<int> ans = {0, 1};
    EXPECT_EQ(s.twoSum(in, target), ans);
}

TEST(twoSum, twoSum_2)
{
    Solution s;
    vector<int> in  = {3, 2, 4};
    int target      = 6;
    vector<int> ans = {1, 2};
    EXPECT_EQ(s.twoSum(in, target), ans);
}

TEST(twoSum, twoSum3)
{
    Solution s;
    vector<int> in  = {3, 3};
    int target      = 6;
    vector<int> ans = {0, 1};
    EXPECT_EQ(s.twoSum(in, target), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}