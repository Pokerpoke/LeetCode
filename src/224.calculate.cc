#include "headers.h"

class Solution
{
public:
    int calculate(string s)
    {
        stack<char> oprs;
        stack<int> nums;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(')
                oprs.push(s[i]);
            else if (s[i] == ')')
            {
                int sum = 0;
                while (oprs.top() != '(')
                {
                    char opr = oprs.top();
                    oprs.pop();
                    int num = nums.top();
                    nums.pop();
                    sum += opr == '+' ? num : -num;
                }
                sum += nums.top();
                nums.pop();
                nums.push(sum);
                oprs.pop();
            }
            else
            {
                string temp = "";
                while (i < n && isdigit(s[i]))
                {
                    temp += s[i];
                    i++;
                }
                nums.push(stoi(temp));
                // if(!oprs.empty()&&)
                if (!oprs.empty() && (oprs.top() == '*' || oprs.top() == '/'))
                {
                    char opr = oprs.top();
                    oprs.pop();
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    nums.push(opr == '*' ? first * second : first / second);
                }
                i--;
            }
        }
        int sum = 0;
        while (!oprs.empty())
        {
            char opr = oprs.top();
            oprs.pop();
            int num = nums.top();
            nums.pop();
            sum += opr == '+' ? num : -num;
        }

        return sum + nums.top();
    }
};

TEST(calculate, calculate_1)
{
    Solution s;
    string in = "1 + 1";
    int ans = 2;
    EXPECT_EQ(s.calculate(in), ans);
}

TEST(calculate, calculate_2)
{
    Solution s;
    string in = "2-1 + 2";
    int ans = 3;
    EXPECT_EQ(s.calculate(in), ans);
}

TEST(calculate, calculate_3)
{
    Solution s;
    string in = "(1+(4+5+2)-3)+(6+8)";
    int ans = 23;
    EXPECT_EQ(s.calculate(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}