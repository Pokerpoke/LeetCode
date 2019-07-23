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
 * Last Modified:  2018-12-21
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    Solution(vector<int> nums) : nums(nums)
    {
    }
    int pick(int target)
    {
        int res = -1, n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != target)
                continue;
            else
            {
                n++;
                if (rand() % n == 0)
                    res = i;
            }
        }
        return res;
    }

  private:
    vector<int> nums;
};

TEST(pick, pick)
{
    vector<int> in = {1, 2, 3, 3, 3};
    Solution s(in);
    EXPECT_EQ(s.pick(1), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}