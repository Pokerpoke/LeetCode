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
 * Last Modified:  2018-08-30
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    else
    {
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
}

int main()
{
    List l;
    for (size_t i = 0; i < 10; i++)
        l.insert(i);

    l.print();

    ListNode *head = l.head;

    l.head = reverseList(head);
    l.print();

    return 0;
}