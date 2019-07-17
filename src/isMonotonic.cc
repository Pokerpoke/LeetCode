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
 * Last Modified:  2019-07-17
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        int n = A.size();
        int flag = 0;
        for (int i = 1; i < n; i++)
        {
            int c = A[i] - A[i - 1];
            if (c > 0)
                c = 1;
            else if (c < 0)
                c = -1;
            if (c != 0)
            {
                if (c != flag && flag != 0)
                    return false;
                flag = c;
            }
        }
        return true;
    }
};

TEST(isMonotonic, isMonotonic_1)
{
    Solution s;
    vector<int> in{1, 2, 2, 3};
    EXPECT_EQ(s.isMonotonic(in), true);
}

TEST(isMonotonic, isMonotonic_2)
{
    Solution s;
    vector<int> in{1, 2, 4, 5};
    EXPECT_EQ(s.isMonotonic(in), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}