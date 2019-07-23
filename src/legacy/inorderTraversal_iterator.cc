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
 * Last Modified:  2018-12-21
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> res;
        while (root != nullptr || !s.empty())
        {
            if (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                res.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};

TEST(inorderTraversal, inorderTraversal)
{
    Solution s;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}