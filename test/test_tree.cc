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
 * Last Modified:  2019-07-30
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool test_tree(string s)
    {
        // Tree t = {1, 2, 3, 4};
        // Tree t{1, 2, 3, NULL, NULL, 4, NULL, NULL, 5, NULL, NULL};
        Tree t{1, 2, 3, 4, NULL, NULL, NULL};
        // Tree t{1, 2, 3, 4, 5, 6, 7, 8, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
        t.print();

        return true;
    }
};

TEST(test_tree, solution)
{
    Solution s;
    EXPECT_TRUE(s.test_tree(""));
}

TEST(test_tree, create)
{
    Tree t1{1, 2, 3, 4, NULL, NULL, NULL};
    Tree t2{1, 2, 3};
    Tree t3{1, 2, NULL, 3};
    Tree t4{1, NULL};
}

TEST(test_tree, create_with_NULL)
{
    Tree t{NULL};
}

TEST(test_tree, print)
{
    Tree t1{1, 2, 3, 4, NULL, NULL, NULL};
    t1.print();
}

TEST(test_tree, print_NULL)
{
    Tree t1{NULL, NULL, NULL};
    t1.print();
}

TEST(test_tree, compare)
{
    Tree t1{1, 2, 3, 4, NULL, NULL, NULL};
    Tree t2{1, 2, 3, NULL, NULL, NULL, NULL};
    Tree t3{1, 2, 3, 4, NULL, NULL, NULL};
    Tree t4{1, 2, 3, 4};
    EXPECT_FALSE(t1 == t2);
    EXPECT_TRUE(t1 == t3);
    EXPECT_TRUE(t1 == t4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}