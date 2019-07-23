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

    if (nums.size() <= 0)
        return 0;

    int i = 0;
    int n = nums.size();
    int cnt = 0;
    int start = 0;
    int cur = nums[i];
    while (cnt++ < n)
    {
        i = (i + k) % n;
        int tmp = nums[i];
        nums[i] = cur;
        if (i == start)
        {
            i++;
            start++;
            cur = nums[i];
        }
        else
        {
            cur = tmp;
        }
    }

    for (auto it : nums)
    {
        cout << it;
    }

    getchar();
    return 0;
}
