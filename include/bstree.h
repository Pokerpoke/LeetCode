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
#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree
{
  public:
    Tree();
    Tree(std::vector<int> &in);
    ~Tree();

    TreeNode *root;

    static void print_tree(TreeNode *root);
    TreeNode *insert_ordered(const std::vector<int> &in, int l, int r);
    void insert(const int &x);
    void insert(const int &x, TreeNode *&parent);
    bool is_empty();
    void print();
};
#endif //!_BSTREE_H_