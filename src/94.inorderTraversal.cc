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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        deque<TreeNode *> stack;
        TreeNode *cur = root;
        while (!stack.empty() || cur != nullptr)
        {
            while (cur != nullptr)
            {
                stack.push_back(cur);
                cur = cur->left;
            }
            res.push_back(stack.back()->val);
            cur = stack.back()->right;
            stack.pop_back();
        }

        return res;
    }
};

TEST(inorderTraversal, inorderTraversal_1)
{
    Solution s;
    Tree in = {1, NULL, 2, 3};
    in.print();
    vector<int> res = {1, 3, 2};
    EXPECT_TRUE(s.inorderTraversal(in.root) == res);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}