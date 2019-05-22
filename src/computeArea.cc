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
 * Last Modified:  2019-05-22
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (C <= E || B >= H || A >= G || D <= F)
            return area;
        else
            return area - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    }
};

TEST(computeArea, computeArea_1)
{
    Solution s;
    int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    EXPECT_EQ(s.computeArea(A, B, C, D, E, F, G, H), 45);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}