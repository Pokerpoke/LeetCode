/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-12
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.begin() + m + n);
    }
};

TEST(merge, merge1)
{
    Solution s;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3, n = 3;
    s.merge(nums1, m, nums2, n);
    for (auto it : nums1)
        cout << it;
    cout << endl;
}

TEST(merge, merge2)
{
    Solution s;
    vector<int> nums1{2, 0};
    vector<int> nums2{1};
    int m = 1, n = 1;
    s.merge(nums1, m, nums2, n);
    for (auto it : nums1)
        cout << it;
    cout << endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}