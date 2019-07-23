/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-08
 * @brief    颠倒整数
 * @version  0.0.1
 * 
 * Last Modified:  2018-08-07
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    // int x = -1234;
    int x = 1534236469;

    int res = 0;

    for (; x != 0; (x /= 10) != 0)
    {
        int tmp = res * 10 + x % 10;
        if (tmp / 10 != res)
            return 0;
        res = tmp;
    }

    cout << res;

    getchar();
    return 0;
}