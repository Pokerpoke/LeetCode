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
 * Last Modified:  2019-07-22
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool test_listnode(string s)
    {
        List l1{1, 2, 3, NULL, NULL, 4, NULL, NULL, 5, NULL, NULL};
        l1.print();
        return true;
    }
};

TEST(test_listnode, test_listnode_1)
{
    Solution s;
    EXPECT_TRUE(s.test_listnode(""));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}