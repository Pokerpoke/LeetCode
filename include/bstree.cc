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

#include "bstree.h"

#include <iostream>
#include <algorithm>

Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(std::vector<int> &in)
{
    root = nullptr;
    sort(in.begin(), in.end());
    for (auto it : in)
        std::cout << it << " ";
    std::cout << std::endl;
    root = insert_ordered(in, 0, in.size() - 1);
    // for (auto it : in)
    //     insert(it);
}

Tree::~Tree() {}

void Tree::print_tree(TreeNode *root)
{
    if (root != nullptr)
    {
        print_tree(root->left);
        std::cout << root->val << " ";
        print_tree(root->right);
    }
}

bool Tree::is_empty()
{
    return (root == nullptr);
}

TreeNode *Tree::insert_ordered(const std::vector<int> &in, int l, int r)
{
    if (l > r)
        return nullptr;
    int mid = (l + r + 1) / 2;
    TreeNode *new_root = new TreeNode(in[mid]);
    new_root->left = insert_ordered(in, l, mid - 1);
    new_root->right = insert_ordered(in, mid + 1, r);
    return new_root;
}

void Tree::insert(const int &x)
{
    insert(x, root);
}

void Tree::insert(const int &x, TreeNode *&parent)
{
    if (parent == nullptr)
    {
        parent = new TreeNode(x);
        return;
    }
    else
    {
        if (x > parent->val)
            return insert(x, parent->right);
        else if (x < parent->val)
            return insert(x, parent->left);
        else
            return;
    }
}

void Tree::print()
{
    print_tree(root);
    std::cout << std::endl;
}