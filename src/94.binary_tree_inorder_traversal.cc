/**
 *
 * Copyright (c) 2023 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2023-06
 * @brief
 *
 * Last Modified:  2023-06-07
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#include "headers.h"

class Solution
{
public:
    vector<int> binary_tree_inorder_traversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stk;
        auto cur = root;
        while (cur != nullptr || !stk.empty())
        {
            while (cur != nullptr)
            {
                stk.emplace(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

TEST(binary_tree_inorder_traversal, binary_tree_inorder_traversal_1)
{
    Solution s;
    Tree in         = {1, NULL, 2, 3};
    vector<int> ans = {1, 3, 2};
    EXPECT_EQ(s.binary_tree_inorder_traversal(in.root), ans);
}

TEST(binary_tree_inorder_traversal, binary_tree_inorder_traversal_2)
{
    Solution s;
    Tree in         = {};
    vector<int> ans = {};
    EXPECT_EQ(s.binary_tree_inorder_traversal(in.root), ans);
}

TEST(binary_tree_inorder_traversal, binary_tree_inorder_traversal_3)
{
    Solution s;
    Tree in         = {1};
    vector<int> ans = {1};
    EXPECT_EQ(s.binary_tree_inorder_traversal(in.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}