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
    int maxSumAfterPartitioning(vector<int> &A, int K)
    {
        return 0;
    }
};

TEST(maxSumAfterPartitioning, maxSumAfterPartitioning)
{
    Solution s;
    vector<int> v = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    EXPECT_EQ(s.maxSumAfterPartitioning(v, k), 84);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}