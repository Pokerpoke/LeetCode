/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-11-12
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode *root, long min, long max)
    {
        if (root == nullptr)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return (isValidBST(root->left, min, root->val) &&
                isValidBST(root->right, root->val, max));
    }
};

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    Solution s;
    // vector<int> in{3, 9, 20, 15, 7};
    vector<int> in{3, 9, 20, 15, 7};
    Tree t(in);
    t.print();

    cout << s.isValidBST(t.root) << endl;

    return RUN_ALL_TESTS();
}
