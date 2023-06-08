#include "headers.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *pre = new ListNode(-1);
        ListNode *res = pre;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                pre->next = list1;
                list1     = list1->next;
            }
            else
            {
                pre->next = list2;
                list2     = list2->next;
            }
            pre = pre->next;
        }
        pre->next = list1 == nullptr ? list2 : list1;
        return res->next;
    }
};

TEST(mergeTwoLists, mergeTwoLists_1)
{
    Solution s;
    List l1  = {1, 2, 4};
    List l2  = {1, 2, 4};
    List ans = {1, 1, 2, 2, 4, 4};

    l1.setRelease(false);
    l2.setRelease(false);
    ans.setRelease(false);

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(l1.head, l2.head), ans.head));
}

TEST(mergeTwoLists, mergeTwoLists_2)
{
    Solution s;
    List l1  = {};
    List l2  = {};
    List ans = {};

    l1.setRelease(false);
    l2.setRelease(false);
    ans.setRelease(false);

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(l1.head, l2.head), ans.head));
}

TEST(mergeTwoLists, mergeTwoLists_3)
{
    Solution s;
    List l1  = {};
    List l2  = {0};
    List ans = {0};

    l1.setRelease(false);
    l2.setRelease(false);
    ans.setRelease(false);

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(l1.head, l2.head), ans.head));
}

TEST(mergeTwoLists, mergeTwoLists_4)
{
    Solution s;
    List l1  = {1, 2, 4};
    List l2  = {1, 3, 4};
    List ans = {1, 1, 2, 3, 4, 4};

    l1.setRelease(false);
    l2.setRelease(false);
    ans.setRelease(false);

    EXPECT_TRUE(is_same_list(s.mergeTwoLists(l1.head, l2.head), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}