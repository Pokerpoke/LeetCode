#include "headers.h"

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        int res;
        q.push(root);
        while (!q.empty())
        {
            res = q.front()->val;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
        }
        return res;
    }
};

TEST(findBottomLeftValue, findBottomLeftValue_1)
{
    Solution s;
    Tree in = {2, 1, 3};
    int ans = 1;
    EXPECT_EQ(s.findBottomLeftValue(in.root), ans);
}

TEST(findBottomLeftValue, findBottomLeftValue_2)
{
    Solution s;
    Tree in = {1, 2, 3, 4, 5, 6, NULL, 7};
    int ans = 7;
    EXPECT_EQ(s.findBottomLeftValue(in.root), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}