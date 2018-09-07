/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-07
 * Modified By:    姜阳 (j824544269@gmail.com)
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
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        return (max(l_depth, r_depth) + 1);
    }
};

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    Solution s;
    vector<int> in{3, 9, 20, 15, 7};
    Tree t(in);
    t.print();

    cout << s.maxDepth(t.root) << endl;

    return RUN_ALL_TESTS();
}
