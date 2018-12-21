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
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> res;
        if (nums.size() == 1)
        {
            res.push_back(nums[0]);
            return res;
        }
        if (nums.size() == 2)
        {
            res.push_back(nums[0]);
            if (nums[1] != nums[0])
                res.push_back(nums[1]);
            return res;
        }

        int num1 = 0, num2 = 0;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1 = count1 > 0 ? count1 - 1 : 0;
                count2 = count2 > 0 ? count2 - 1 : 0;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
                count1++;
            if (nums[i] == num2)
                count2++;
        }
        if (count1 > nums.size() / 3)
            res.push_back(num1);
        if (count2 > nums.size() / 3 && num1 != num2)
            res.push_back(num2);
        return res;
    }
};

TEST(majorityElement, majorityElement1)
{
    Solution s;
    vector<int> in{3, 2, 3};
    vector<int> ans{3};
    vector<int> res = s.majorityElement(in);
    EXPECT_EQ(ans.size(), res.size());
    for (int i = 0; i < ans.size(); i++)
        EXPECT_EQ(ans[i], res[i]);
}
TEST(majorityElement, majorityElement2)
{
    Solution s;
    vector<int> in{1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> ans{1, 2};
    vector<int> res = s.majorityElement(in);
    EXPECT_EQ(ans.size(), res.size());
    for (int i = 0; i < ans.size(); i++)
        EXPECT_EQ(ans[i], res[i]);
}
TEST(majorityElement, majorityElement3)
{
    Solution s;
    vector<int> in{0, 0, 0};
    vector<int> ans{0};
    vector<int> res = s.majorityElement(in);
    EXPECT_EQ(ans.size(), res.size());
    for (int i = 0; i < ans.size(); i++)
        EXPECT_EQ(ans[i], res[i]);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}