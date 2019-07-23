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
 * Last Modified:  2018-08-25
 * Modified By:    姜阳 (j824544269@gmail.com)
 *
 */
#include "headers.h"

int main()
{
    string haystack = "hello";
    // string haystack = "";
    string needle = "ll";

    if (needle.empty())
        return 0;

    int m = haystack.size(), n = needle.size();
    if (m < n)
        return -1;

    for (int i = 0; i < m - n; i++)
    {
        int j = 0;
        for (; j < n; j++)
        {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == n)
        {
            cout << i;
            getchar();
            return i;
        }
    }
    cout << -1;
    getchar();
    return -1;

    getchar();
    return 0;
}