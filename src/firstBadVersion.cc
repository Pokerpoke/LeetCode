/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-12
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

bool isBadVersion(int version)
{
    return version >= 1702766719 ? true : false;
}

class Solution
{
  public:
    int firstBadVersion(int n)
    {
        if (n < 1)
            return 0;
        long l = 1, r = n;
        long mid = (l + r) / 2;
        while (l < r)
        {
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
            mid = (l + r) / 2;
        }
        return l;
    }
};

TEST(firstBadVersion, firstBadVersion)
{
    Solution s;
    EXPECT_EQ(s.firstBadVersion(5), 2);
    EXPECT_EQ(s.firstBadVersion(2), 2);
    EXPECT_EQ(s.firstBadVersion(2126753390), 1702766719);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}