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
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                             vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size())
        {
            vector<int> t = mix(A[i], B[j]);
            if (t.empty())
            {
                if (A[i][0] < B[j][1])
                    i++;
                else
                    j++;
            }
            else
            {
                res.push_back(t);
                if (A[i][1] < B[j][1])
                    i++;
                else
                    j++;
            }
        }
        return res;
    }

    vector<int> mix(vector<int> &A, vector<int> &B)
    {
        vector<int> res;
        if (A[0] > B[1] || A[1] < B[0])
            return res;
        else
        {
            res.push_back(max(A[0], B[0]));
            res.push_back(min(A[1], B[1]));
            return res;
        }
    }
};

TEST(intervalIntersection, intervalIntersection_1)
{
    Solution s;
    vector<vector<int>> A{{0, 2},
                          {5, 10},
                          {13, 23},
                          {24, 25}};
    vector<vector<int>> B{{1, 5},
                          {8, 12},
                          {15, 24},
                          {25, 26}};
    vector<vector<int>> res{{1, 2},
                            {5, 5},
                            {8, 10},
                            {15, 23},
                            {24, 24},
                            {25, 25}};

    EXPECT_EQ(s.intervalIntersection(A, B), res);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}