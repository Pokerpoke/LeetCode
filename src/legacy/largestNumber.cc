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
 * Last Modified:  2019-06-24
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            auto aa = to_string(a);
            auto bb = to_string(b);
            return aa + bb > bb + aa;
        });
        return accumulate(nums.begin(), nums.end(), string(), [](string &a, int b) {
            if (a == "0")
                return to_string(b);
            return move(a) + to_string(b);
        });
    }
};

TEST(largestNumber, largestNumber_1)
{
    Solution s;
    vector<int> in = {10, 2};
    EXPECT_EQ(s.largestNumber(in), "210");
}

TEST(largestNumber, largestNumber_2)
{
    Solution s;
    vector<int> in = {3, 30, 34, 5, 9};
    EXPECT_EQ(s.largestNumber(in), "9534330");
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}