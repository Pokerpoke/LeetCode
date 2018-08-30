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

int main()
{
    List l;
    for (size_t i = 0; i < 2; i++)
        l.insert(i);

    l.print();

    ListNode *head = l.head;

    if (head->next == nullptr || head == nullptr)
        // return head;
        cout << "head";

    ListNode *pre = head;
    ListNode *cur = head->next;

    pre->next = nullptr;

    while (cur != nullptr)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    l.head = pre;
    l.print();

    return 0;
}