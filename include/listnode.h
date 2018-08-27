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
 * Last Modified:  2018-08-27
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *p = nullptr) : val(x), next(nullptr){};
};

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
        ListNode *p = head;
        while (p != nullptr)
        {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};

#endif //!_LISTNODE_H_