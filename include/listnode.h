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
 * Last Modified:  2018-08-31
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>
#include <vector>

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

class List
{
    //   private:

  public:
    ListNode *head, *tail;
    int pos;

    List()
    {
        head = nullptr;
        tail = nullptr;
    };
    List(const std::vector<int> &in)
    {
        head = nullptr;
        tail = nullptr;
        for (auto it : in)
            this->insert(it);
    };

    ~List(){};

    void insert(int x)
    {
        if (head == nullptr)
        {
            head = tail = new ListNode(x);
            head->next = nullptr;
            tail->next = nullptr;
        }
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
        print_list(head);
    }
};

#endif //!_LISTNODE_H_