#include "headers.h"

class Solution
{
public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr))
            return 0;
        int res = INT_MIN;
        stack<TreeNode *> s;
        map<TreeNode *, vector<int>> m;
        s.push(root);
        m[root].push_back(root->val);
        m[root].push_back(root->val);
        int i = 0;
        TreeNode *parent = root;
        while (!s.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                if (m[root].empty())
                {
                    m[root].push_back(max(root->val, m[parent][0]));
                    m[root].push_back(min(root->val, m[parent][1]));
                }
                else
                {
                    m[root][0] = max(root->val, m[root][0]);
                    m[root][1] = min(root->val, m[root][1]);
                }
                s.push(root);
                parent = root;
                res = max(res, m[root][0] - m[root][1]);
                root = root->left;
            }
            if (!s.empty())
            {
                root = s.top();
                parent = root;
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};

TEST(maxAncestorDiff, maxAncestorDiff_1)
{
    Solution s;
    Tree t = {8, 3, 10, 1, 6, NULL, 14, NULL, NULL, 4, 7, 13};
    TreeNode *in = t.root;
    int ans = 7;
    EXPECT_EQ(s.maxAncestorDiff(in), ans);
}

TEST(maxAncestorDiff, maxAncestorDiff_2)
{
    Solution s;
    Tree t = {2, NULL, -1, NULL, 4, NULL, 3, NULL, 1};
    TreeNode *in = t.root;
    int ans = 5;
    EXPECT_EQ(s.maxAncestorDiff(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}