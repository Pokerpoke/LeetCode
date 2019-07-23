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
 * Last Modified:  2018-08-29
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    List l;
    for (size_t i = 0; i < 10; i++)
        l.insert(i);

    l.print();

    int n = 3;

    ListNode *slow = l.head;
    ListNode *fast = l.head;

    if (fast == nullptr)
        // return l.head->next;
        cout << "head->next";

    for (size_t i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    l.print();

    getchar();
    return 0;
}