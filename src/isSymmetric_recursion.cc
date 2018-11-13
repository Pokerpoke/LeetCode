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
 * Last Modified:  2018-11-13
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr)
            return true;
        else if (l == nullptr || r == nullptr)
            return false;
        return (l->val == r->val) &&
               isSymmetric(l->left, r->right) &&
               isSymmetric(l->right, r->left);
    }
};

TEST(isSymmetric, isSymmetric)
{
    // Solution s;
    // Tree t;
    // vector<int> v = {1, 2, 2, 3, 4, 4, 3};
    // for (auto i : v)
    // {
    //     t.insert(i);
    // }
    // EXPECT_TRUE(s.isSymmetric(t.root));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}