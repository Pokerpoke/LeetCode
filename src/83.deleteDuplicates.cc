/**
 *
 * Copyright (c) 2023 Pokerpoke
 *
 * @file
 * @author   Pokerpoke (pokerpoke@qq.com)
 * @date     2023-06
 * @brief
 *
 * Last Modified:  2023-06-08
 * Modified By:    Pokerpoke (pokerpoke@qq.com)
 *
 */

#include "headers.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        auto cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};

TEST(deleteDuplicates, deleteDuplicates_1)
{
    Solution s;
    List in  = {1, 1, 2};
    List ans = {1, 2};
    in.setRelease(false);
    ans.setRelease(false);
    EXPECT_TRUE(is_same_list(s.deleteDuplicates(in.head), ans.head));
}

TEST(deleteDuplicates, deleteDuplicates_2)
{
    Solution s;
    List in  = {1, 1, 2, 3, 3};
    List ans = {1, 2, 3};
    in.setRelease(false);
    ans.setRelease(false);
    EXPECT_TRUE(is_same_list(s.deleteDuplicates(in.head), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}