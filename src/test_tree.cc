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

TEST(test_tree, test_tree_1)
{
    Solution s;
    EXPECT_TRUE(s.test_tree(""));
    // EXPECT_EQ(s.test_tree(""), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}