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

// TODO: add tests
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    vector<int> in{1, 2};
    List l(in);
    l.print();
    Solution s;

    // l.print_list(s.isPalindrome(l.head));
    cout << s.hasCycle(l.head) << endl;

    return RUN_ALL_TESTS();
}
