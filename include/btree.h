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
 * Last Modified:  2019-07-23
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <vector>
#include <iostream>
#include <initializer_list>
#include <queue>
#include <list>
namespace LeetCode
{

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = NULL) : val(x), left(nullptr), right(nullptr) {}
};

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
    return true;
}

class Tree
{
public:
    TreeNode *root;

private:
    std::queue<int> q;

public:
    Tree(std::initializer_list<int> il) : q(il)
    {
        if (q.size() <= 0)
            return;
        root = deserialize(q);
    }

    TreeNode *deserialize(std::queue<int> &in)
    {
        if (in.front() == NULL)
            return nullptr;

        TreeNode *temp = new TreeNode(in.front());
        in.pop();
        temp->left = deserialize(in);
        temp->right = deserialize(in);

        return temp;
    }

    ~Tree() {}

    void print()
    {
        print_tree(root);
        std::cout << std::endl;
    }

    bool operator==(const Tree &t2)
    {
        return compare_tree(root, t2.root);
    }
};
} // namespace LeetCode

#endif //!_BSTREE_H_