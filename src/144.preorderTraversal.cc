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
 * Last Modified:  2019-08-13
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        while (root != nullptr || !s.empty())
        {
            if(root!=nullptr)
            {
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top()->right;
                s.pop();
            }
        }
        return res;
    }
};

TEST(preorderTraversal, preorderTraversal_1)
{
    Solution s;
    Tree in = {1, NULL, 2, 3};
    vector<int> ans = {1, 2, 3};
    EXPECT_EQ(s.preorderTraversal(in.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}