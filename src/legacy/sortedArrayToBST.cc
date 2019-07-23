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
 * Last Modified:  2018-09-07
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = (start + end + 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    Solution s;
    vector<int> in{-10, -3, 0, 5, 9};

    Tree::print_tree(s.sortedArrayToBST(in));

    return RUN_ALL_TESTS();
}
