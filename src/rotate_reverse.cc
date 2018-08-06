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
 * Last Modified:  2018-08-04
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    int n = nums.size();
    if (n == 0 || n == 1)
    {
        return 0;
    }

    if (k >= n)
    {
        k = k % n;
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    for (auto it : nums)
    {
        cout << it;
    }

    getchar();
    return 0;
}
