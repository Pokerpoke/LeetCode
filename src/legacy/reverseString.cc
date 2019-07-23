/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-08
 * @brief    反转字符串
 * @version  0.0.1
 * 
 * Last Modified:  2018-08-07
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    string s = "hello";
    reverse(s.begin(), s.end());

    cout << s;

    getchar();
    return 0;
}