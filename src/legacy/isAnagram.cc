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
    string s("anagram");
    string t("nagaram");

    int cnt_s[26] = {0}, cnt_t[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        cnt_s[(s[i] - 'a')]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        cnt_t[(t[i] - 'a')]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt_s[i] != cnt_t[i])
            cout << "false";
        // return false
    }
    cout << "true";
    // return true

    getchar();
    return 0;
}