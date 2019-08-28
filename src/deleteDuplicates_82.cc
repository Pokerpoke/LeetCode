/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-26
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    ListNode *deleteDuplicates_82(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *t_head = head;
        int index = 0;
        map<int, set<int>> m;
        while (t_head != nullptr)
        {
            m[t_head->val].insert(index);
            t_head = t_head->next;
            index++;
        }
        index = 0;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            // delete
            if (m[cur->val].size() > 1 && m[cur->val].count(index) > 0)
            {
                if (pre == nullptr)
                    head = head->next;
                else
                    pre->next = cur->next;
                cout << index << endl;
            }
            // do not delete
            else
            {
                if (pre == nullptr)
                    pre = cur;
                else
                    pre = pre->next;
            }
            cur = cur->next;
            index++;
        }
        return head;
    }
};

TEST(deleteDuplicates_82, deleteDuplicates_82_1)
{
    Solution s;
    List in = {1, 2, 3, 3, 4, 4, 5};
    List ans = {1, 2, 5};
    EXPECT_TRUE(is_same_list(s.deleteDuplicates_82(in.head), ans.head));
}

TEST(deleteDuplicates_82, deleteDuplicates_82_2)
{
    Solution s;
    List in = {1, 1, 1, 2, 3};
    List ans = {2, 3};
    EXPECT_TRUE(is_same_list(s.deleteDuplicates_82(in.head), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}