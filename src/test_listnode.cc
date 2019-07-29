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
 * Last Modified:  2019-07-29
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool test_listnode(vector<int> A)
    {
        List l1;
        for (auto it : A)
            l1.insert(it);
        l1.print();
        return true;
    }
};

TEST(test_listnode, create)
{
    List l1{1, 2, 3};
}

TEST(test_listnode, print)
{
    List l1{1, 2, 3};
    l1.print();
}

TEST(test_listnode, compare)
{
    List l1{1, 2, 3, 4};
    List l2{1, 2, 3, 4};
    List l3{1, 2, 3, 5};
    EXPECT_TRUE(l1 == l2);
    EXPECT_FALSE(l1 == l3);
}

TEST(test_listnode, solution)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    s.test_listnode(in);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}