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
 * Last Modified:  2019-08-21
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool isBoomerang_1037(vector<vector<int>> &points)
    {
        int x1 = points[1][0] - points[0][0];
        int x2 = points[2][0] - points[0][0];
        int y1 = points[1][1] - points[0][1];
        int y2 = points[2][1] - points[0][1];
        return x1 * y2 != y1 * x2;
    }
};

TEST(isBoomerang_1037, isBoomerang_1037_1)
{
    Solution s;
    vector<vector<int>> in = {{1, 1},
                              {2, 3},
                              {3, 2}};
    bool ans = true;
    EXPECT_EQ(s.isBoomerang_1037(in), ans);
}

TEST(isBoomerang_1037, isBoomerang_1037_2)
{
    Solution s;
    vector<vector<int>> in = {{1, 1},
                              {2, 2},
                              {3, 3}};
    bool ans = false;
    EXPECT_EQ(s.isBoomerang_1037(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}