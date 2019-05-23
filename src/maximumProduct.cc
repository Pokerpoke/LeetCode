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
 * Last Modified:  2019-05-23
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN,
            max2 = INT_MIN,
            max3 = INT_MIN,
            min1 = INT_MAX,
            min2 = INT_MAX;
        for (auto num : nums)
        {
            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }
            if (num > max3)
            {
                max1 = max2;
                max2 = max3;
                max3 = num;
            }
            else if (num > max2)
            {
                max1 = max2;
                max2 = num;
            }
            else if (num > max1)
            {
                max1 = num;
            }
        }
        return max(max1 * max2 * max3,
                   min1 * min2 * max3);
    }
};

TEST(maximumProduct, maximumProduct_1)
{
    Solution s;
    vector<int> v{1, 2, 3};
    EXPECT_EQ(s.maximumProduct(v), 6);
}

TEST(maximumProduct, maximumProduct_2)
{
    Solution s;
    vector<int> v{1, 2, 3, 4};
    EXPECT_EQ(s.maximumProduct(v), 24);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}