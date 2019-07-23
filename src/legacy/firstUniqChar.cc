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
 * Last Modified:  2018-08-29
 * Modified By:    姜阳 (j824544269@gmail.com)
 *
 */
#include "headers.h"

int main()
{
    // string s("leetcode");
    string s("loveleetcode");

    if (s.size() == 0)
        return -1;
    int cnt[26] = {0};
    // memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < s.size(); i++)
        cnt[(s[i] - 'a')]++;

    for (int i = 0; i < s.size(); i++)
    {
        if (cnt[(s[i] - 'a')] == 1)
            cout << i;
    }

    getchar();
    return 0;
}