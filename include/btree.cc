/**
 * 
 * Copyright (c) 2019 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-07-29
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "btree.h"

namespace LeetCode
{
void print_tree(TreeNode *root)
{
    using std::cout;
    using std::endl;
    if (root != nullptr)
    {
        cout << root->val << " ";
        print_tree(root->left);
        print_tree(root->right);
    }
    else
        cout << "NULL ";
}

bool compare_tree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    else if (root1 == nullptr || root2 == nullptr)
        return false;
    else if (root1->val == root2->val)
        return (compare_tree(root1->left, root2->left) &&
                compare_tree(root1->right, root2->right));
    return false;
}

Tree::Tree(std::initializer_list<int> il) : q(il)
{
    if (q.empty())
        return;
    this->root = deserialize(q);
}

void delete_root_helper(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *p_left = root->left;
    TreeNode *p_right = root->right;
    delete root;
    root = nullptr;
    if (p_left != nullptr)
        delete_root_helper(p_left);
    if (p_right != nullptr)
        delete_root_helper(p_right);
    return;
}

Tree::~Tree()
{
    delete_root_helper(root);
}

TreeNode *Tree::deserialize(std::queue<int> &in)
{
    if (in.empty() || in.front() == NULL)
        return nullptr;

    TreeNode *temp = new TreeNode(in.front());
    in.pop();
    temp->left = deserialize(in);
    temp->right = deserialize(in);

    return temp;
}

void Tree::print()
{
    print_tree(this->root);
    std::cout << std::endl;
}

bool Tree::operator==(const Tree &t2) const
{
    return compare_tree(this->root, t2.root);
}
} // namespace LeetCode