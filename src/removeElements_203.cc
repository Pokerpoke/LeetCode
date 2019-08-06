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
 * Last Modified:  2019-08-06
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    ListNode *removeElements_203(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *vhead = new ListNode(-1);
        vhead->next = head;
        head = vhead;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                cur = cur->next;
                pre->next = pre->next->next;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head->next;
    }
};

TEST(removeElements_203, removeElements_203_1)
{
    Solution s;
    List in = {1, 2, 6, 3, 4, 5, 6};
    List ans = {1, 2, 3, 4, 5};
    int val = 6;
    EXPECT_TRUE(is_same_list(s.removeElements_203(in.head, val), ans.head));
}

TEST(removeElements_203, removeElements_203_2)
{
    Solution s;
    List in = {};
    List ans = {};
    int val = 6;
    EXPECT_TRUE(is_same_list(s.removeElements_203(in.head, val), ans.head));
}

TEST(removeElements_203, removeElements_203_3)
{
    Solution s;
    List in = {1, 1};
    List ans = {};
    int val = 1;
    EXPECT_TRUE(is_same_list(s.removeElements_203(in.head, val), ans.head));
}

TEST(removeElements_203, removeElements_203_4)
{
    Solution s;
    List in = {1, 2, 6, 3, 4, 5, 6};
    List ans = {2, 6, 3, 4, 5, 6};
    int val = 1;
    EXPECT_TRUE(is_same_list(s.removeElements_203(in.head, val), ans.head));
}

TEST(removeElements_203, removeElements_203_5)
{
    Solution s;
    List in = {1, 2, 2, 2, 2, 2, 6};
    List ans = {1, 6};
    int val = 2;
    EXPECT_TRUE(is_same_list(s.removeElements_203(in.head, val), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}