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
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        long res = 0;
        for (int i = 0; i < rectangles.size(); i++)
        {
            for (int j = 0; j < rectangles.size(); j++)
            {
                if (j == i)
                    continue;
                res += computerArea(rectangles[i], rectangles[j]);
            }
        }
        cout << res << endl;
        return res % (1000000000 + 7);
    }
    long computerArea(vector<int> &a, vector<int> &b)
    {
        long res = (a[2] - a[0]) * (a[3] - a[1]) + (b[2] - b[0]) * (b[3] - b[1]);
        if (b[0] >= a[2] || b[1] >= a[3] || b[2] <= a[0] || b[3] <= a[1])
            return res;
        else
            return res - (min(a[2], b[2]) - max(a[0], b[0])) * (min(a[3], b[3]) - max(a[1], b[1]));
    }
};

TEST(rectangleArea, rectangleArea_1)
{
    Solution s;
    vector<vector<int>> v{{0, 0, 2, 2},
                          {1, 0, 2, 3},
                          {1, 0, 3, 1}};
    EXPECT_EQ(s.rectangleArea(v), 6);
}

TEST(rectangleArea, rectangleArea_2)
{
    Solution s;
    vector<vector<int>> v{{0, 0, 1000000000, 1000000000}};
    EXPECT_EQ(s.rectangleArea(v), 49);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}