#include "headers.h"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;

        auto slow = head;
        auto fast = head->next;

        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

TEST(hasCycle, hasCycle_1)
{
    Solution s;
    ListNode *in = new ListNode(3);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(0);
    auto l4 = new ListNode(-4);
    in->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;
    bool ans = true;
    EXPECT_EQ(s.hasCycle(in), ans);
}

TEST(hasCycle, hasCycle_2)
{
    Solution s;
    ListNode *in = new ListNode(1);
    auto l2 = new ListNode(2);
    in->next = l2;
    l2->next = in;
    bool ans = true;
    EXPECT_EQ(s.hasCycle(in), ans);
}

TEST(hasCycle, hasCycle_3)
{
    Solution s;
    ListNode *in = new ListNode(1);
    bool ans = false;
    EXPECT_EQ(s.hasCycle(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}