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
#include "headers.h"

int main()
{
    List l;
    l.insert(1);
    l.insert(10);
    l.insert(10);
    l.insert(10);

    l.print();

    ListNode *node = l.head;

    if (node->next == nullptr)
        node = nullptr;
    node->val = node->next->val;
    node->next = node->next->next;

    l.print();

    getchar();
    return 0;
}