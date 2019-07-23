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
        stack<TreeNode *> s;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        s.push(l);
        s.push(r);
        while (!s.empty())
        {
            l = s.top();
            s.pop();
            r = s.top();
            s.pop();
            if (l == nullptr && r == nullptr)
                continue;
            if (l == nullptr || r == nullptr)
                return false;
            if (l->val != r->val)
                return false;

            s.push(l->left);
            s.push(r->right);
            s.push(l->right);
            s.push(r->left);
        }
        return true;
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