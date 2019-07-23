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
 * Last Modified:  2019-05-21
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2)
            return false;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == 0 && nums[i + 1] == 0)
                return true;
        if (k == 0)
            return false;
        k = abs(k);

        unordered_map<int, int> m;
        // m.insert(pair<int, int>(0, -1));
        m.insert({0, -1});
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int mod = sum % k;
            if (m.count(mod) != 0)
            {
                if (i - m[mod] > 1)
                    return true;
            }
            else
                // m.insert(pair<int, int>(mod, i));
                m.insert({mod, i});
        }
        return false;
    }
};

TEST(checkSubarraySum, checkSubarraySum1)
{
    Solution s;
    vector<int> v = {1, 2, 3};
    int k = 6;
    EXPECT_TRUE(s.checkSubarraySum(v, k));
}

TEST(checkSubarraySum, checkSubarraySum2)
{
    Solution s;
    vector<int> v = {1, 2, 3};
    int k = 5;
    EXPECT_TRUE(s.checkSubarraySum(v, k));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}