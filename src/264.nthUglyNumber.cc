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
 * Last Modified:  2019-08-02
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> res{1};
        for (int i = 0; i < n - 1; i++)
        {
            int temp = min(res[i2] * 2, min(res[i3] * 3, res[i5] * 5));
            res.push_back(temp);
            if (temp == res[i2] * 2)
                i2++;
            if (temp == res[i3] * 3)
                i3++;
            if (temp == res[i5] * 5)
                i5++;
        }
        return res.back();
    }
};

TEST(nthUglyNumber, nthUglyNumber_1)
{
    Solution s;
    EXPECT_EQ(s.nthUglyNumber(10), 12);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}