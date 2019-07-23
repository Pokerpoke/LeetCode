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
#include "headers.h"

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *head, *tail;
        if (l1->val < l2->val)
        {
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            tail = l2;
            l2 = l2->next;
        }
        head = tail;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 == nullptr)
        {
            tail->next = l2;
        }
        if (l2 == nullptr)
        {
            tail->next = l1;
        }
        return head;
    }
};

int add()
{
    return 4;
}

TEST(Addition, Addition2)
{
    EXPECT_EQ(4, add());
    vector<int> in{1, 2};
    List l1(in);
    vector<int> in2{1, 2, 2, 3, 8};
    List l2(in2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    vector<int> in{1, 2};
    List l1(in);
    vector<int> in2{1, 2, 2, 3, 8};
    List l2(in2);
    l1.print();
    l2.print();

    Solution s;

    // s.mergeTwoLists(l1.head, l2.head);

    l1.print_list(s.mergeTwoLists(l1.head, l2.head));

    return RUN_ALL_TESTS();
}
