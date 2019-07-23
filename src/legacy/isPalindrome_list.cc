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
 * Last Modified:  2018-09-04
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    ListNode *find_middle(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverse_list(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        else
        {
            ListNode *newhead = reverse_list(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newhead;
        }
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *mid = find_middle(head);
        ListNode *reverse_head = reverse_list(mid);
        // cout << "head ";
        // print_list(head);
        // cout << "reverse_head " << reverse_head->next->val;
        // print_list(reverse_head);
        while (head != nullptr &&
               reverse_head != nullptr &&
               head->val == reverse_head->val)
        {
            head = head->next;
            reverse_head = reverse_head->next;
        }
        return (reverse_head == nullptr);
    }
};

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    // vector<int> in{1, 3, 4, 3, 1};
    // vector<int> in{1, 2};
    vector<int> in{1, 2};
    List l(in);
    // l.print();

    Solution s;

    // l.print_list(s.isPalindrome(l.head));
    cout << s.isPalindrome(l.head) << endl;

    return RUN_ALL_TESTS();
}
