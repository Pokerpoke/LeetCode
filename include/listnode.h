/**
 * 
 * Copyright (c) 2019 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-03
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>
#include <vector>
#include <initializer_list>

namespace LeetCode
{
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *p = nullptr) : val(x), next(nullptr){};
};

void print_list(ListNode *head);
bool is_same_list(ListNode *l1, ListNode *l2);

class List
{
public:
    ListNode *head;

private:
    ListNode *tail;

public:
    List();
    List(std::initializer_list<int> l);
    ~List();
    void insert(int x);
    void print();
    bool operator==(const List &l1) const;
};
} // namespace LeetCode

#endif //!_LISTNODE_H_