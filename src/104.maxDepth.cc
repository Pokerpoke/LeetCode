/**
 *
 * Copyright (c) 2022 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2022-03
 * @brief
 *
 * Last Modified:  2022-03-18
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#include "headers.h"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto n = q.size();

            for (int i = 0; i < n; i++)
            {
                auto cur_node = q.front();
                q.pop();

                if (cur_node->left != nullptr)
                    q.push(cur_node->left);
                if (cur_node->right != nullptr)
                    q.push(cur_node->right);
            }

            res++;
        }

        return res;
    }
};

TEST(maxDepth, maxDepth_1)
{
    Solution s;
    Tree in{{3, 9, 20, 0, 0, 15, 7}};
    int ans = 3;
    EXPECT_EQ(s.maxDepth(in.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}