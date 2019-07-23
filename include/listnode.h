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
 * Last Modified:  2019-07-22
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

void print_list(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

bool compare_list(ListNode *l1, ListNode *l2)
{
    while (l1 != nullptr && l2 != nullptr && l1->val == l2->val)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == l2 ? true : false;
}

class List
{
public:
    ListNode *head, *tail;
    int pos;

    List()
    {
        head = nullptr;
    };

    List(std::initializer_list<int> l)
        : head(nullptr), tail(nullptr)
    {
        for (auto it : l)
            insert(it);
    };

    ~List(){};

    void insert(int x)
    {
        if (head == nullptr)
            head = tail = new ListNode(x);
        else
        {
            ListNode *p = new ListNode(x);
            tail->next = p;
            tail = p;
            tail->next = nullptr;
        }
    };

    void print()
    {
        print_list(this->head);
    }

    bool operator==(const List &l1) const
    {
        // ListNode *head1 = this->head;
        // ListNode *head2 = l1.head;
        return compare_list(this->head, l1.head);
    }
};
} // namespace LeetCode

#endif //!_LISTNODE_H_