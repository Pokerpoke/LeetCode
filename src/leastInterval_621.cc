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
 * Last Modified:  2019-08-09
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leastInterval_621(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);
        int max_cnt = 0;
        for (auto task : tasks)
        {
            cnt[task - 'A']++;
            max_cnt = max(max_cnt, cnt[task - 'A']);
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i] == max_cnt)
                count++;
        int res = (max_cnt - 1) * (n + 1) + count;
        return max(res, (int)tasks.size());
    }
};

TEST(leastInterval_621, leastInterval_621_1)
{
    Solution s;
    vector<char> in = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int ans = 8;
    EXPECT_EQ(s.leastInterval_621(in, n), ans);
}

TEST(leastInterval_621, leastInterval_621_2)
{
    Solution s;
    vector<char> in = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 0;
    int ans = 6;
    EXPECT_EQ(s.leastInterval_621(in, n), ans);
}

TEST(leastInterval_621, leastInterval_621_3)
{
    Solution s;
    vector<char> in = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 50;
    int ans = 104;
    EXPECT_EQ(s.leastInterval_621(in, n), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}