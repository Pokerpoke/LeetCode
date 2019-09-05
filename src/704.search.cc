#include "headers.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
};

TEST(search, search_1)
{
    Solution s;
    vector<int> in = {-1, 0, 3, 5, 9, 12};
    int in2 = 9;
    int ans = 4;
    EXPECT_EQ(s.search(in, in2), ans);
}

TEST(search, search_2)
{
    Solution s;
    vector<int> in = {-1, 0, 3, 5, 9, 12};
    int in2 = 2;
    int ans = -1;
    EXPECT_EQ(s.search(in, in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}