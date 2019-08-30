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
 * Last Modified:  2019-08-30
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, res = 0;
        while (i <= j)
        {
            res++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }
        return res;
    }
};

TEST(numRescueBoats, numRescueBoats_1)
{
    Solution s;
    vector<int> in = {1, 2};
    int limit = 3;
    int ans = 1;
    EXPECT_EQ(s.numRescueBoats(in, limit), ans);
}

TEST(numRescueBoats, numRescueBoats_2)
{
    Solution s;
    vector<int> in = {3, 2, 2, 1};
    int limit = 3;
    int ans = 3;
    EXPECT_EQ(s.numRescueBoats(in, limit), ans);
}

TEST(numRescueBoats, numRescueBoats_3)
{
    Solution s;
    vector<int> in = {3, 5, 3, 4};
    int limit = 5;
    int ans = 4;
    EXPECT_EQ(s.numRescueBoats(in, limit), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}