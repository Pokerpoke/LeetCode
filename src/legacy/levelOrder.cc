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
 * Last Modified:  2018-11-14
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        vector<int> level;

        if (root == nullptr)
            return ret;
        q.push(root);
        while (!q.empty())
        {
            level.clear();
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *p = q.front();
                level.push_back(p->val);
                q.pop();
                if (p->left != nullptr)
                    q.push(p->left);
                if (p->right != nullptr)
                    q.push(p->right);
            }
            ret.push_back(level);
        }
        return ret;
    }
};

TEST(levelOrder, levelOrder)
{
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}