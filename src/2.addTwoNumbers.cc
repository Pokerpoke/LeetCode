#include "headers.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *head = res;
        int flag = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = 0;
            if (l1 == nullptr)
            {
                sum = flag + l2->val;
                l2 = l2->next;
            }
            else if (l2 == nullptr)
            {
                sum = flag + l1->val;
                l1 = l1->next;
            }
            else
            {
                sum = flag + l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            head->next = new ListNode(sum % 10);
            head = head->next;
            flag = sum / 10;
        }
        if (flag == 1)
            head->next = new ListNode(flag);
        return res->next;
    }
};

TEST(addTwoNumbers, addTwoNumbers_1)
{
    Solution s;
    List l1{2, 4, 3};
    List l2{5, 6, 4};
    List ans{7, 0, 8};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(l1.head, l2.head), ans.head));
}

TEST(addTwoNumbers, addTwoNumbers_2)
{
    Solution s;
    List l1{0, 1};
    List l2{0, 1, 2};
    List ans{0, 2, 2};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(l1.head, l2.head), ans.head));
}
TEST(addTwoNumbers, addTwoNumbers_3)
{
    Solution s;
    List l1{};
    List l2{0, 1};
    List ans{0, 1};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(l1.head, l2.head), ans.head));
}
TEST(addTwoNumbers, addTwoNumbers_4)
{
    Solution s;
    List l1{9, 9};
    List l2{1};
    List ans{0, 0, 1};
    EXPECT_TRUE(is_same_list(s.addTwoNumbers(l1.head, l2.head), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}