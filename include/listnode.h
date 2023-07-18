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
 * Last Modified:  2023-07-18
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
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
    ListNode(int x = 0, ListNode *p = nullptr) : val(x), next(p){};
};

void print_list(ListNode *head);
bool is_same_list(ListNode *l1, ListNode *l2);

class List
{
public:
    ListNode *head;

private:
    ListNode *tail;
    bool m_release = true;

public:
    List();
    List(std::initializer_list<int> l);
    ~List();
    void insert(int x);
    void print();
    // 是否删除链表
    // 某些题目中会使用两个链表，删除两次会出错
    // 开启后会造成内存泄漏
    void setRelease(bool release = true);
    bool operator==(const List &l1) const;
};
} // namespace LeetCode

#endif //!_LISTNODE_H_