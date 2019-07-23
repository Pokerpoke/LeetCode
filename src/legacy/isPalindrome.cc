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
 * Last Modified:  2018-08-22
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    string s("A man, a plan, a canal: Panama");
    // string s(" man, a plan, a canal: Panama");

    int left = 0, right = s.size();

    while (left < right)
    {
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) != tolower(s[right]))
            cout << "false";
        else
        {
            left++;
            right--;
        }
    }
    cout << "true";

    getchar();
    return 0;
}