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
 * Last Modified:  2018-11-27
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        if (A.empty() || A.size() < 3)
            return 0;
        int sum = 0, count = 0;
        int n = A.size();
        for (int i = 2; i < n; i++)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                count++;
                sum += count;
            }
            else
                count = 0;
        }
        return sum;
    }
};

TEST(numberOfArithmeticSlices, numberOfArithmeticSlices)
{
    Solution s;
    vector<int> A{1, 2, 3, 4};
    EXPECT_EQ(s.numberOfArithmeticSlices(A), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}