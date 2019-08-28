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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != nullptr && root->val != val)
        {
            if (root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};

TEST(searchBST, searchBST_1)
{
    Solution s;
    Tree in = {4, 2, 7, 1, 3};
    Tree res = {2, 1, 3};
    EXPECT_TRUE(is_same_tree(s.searchBST(in.root, 2), res.root));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}