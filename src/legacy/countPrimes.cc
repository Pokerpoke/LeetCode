/**
 *
 * Copyright (c) 2018 NUAA Jiang Yang
 *
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-09
 * @brief
 * @version  0.0.1
 *
 * Last Modified:  2018-09-10
 * Modified By:    姜阳 (pokerpoke@qq.com)
 *
 */
#include "headers.h"

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 0)
            return 0;
        //bool prime[n] = {true};
        bool *prime = new bool[n];
        memset(prime, true, sizeof(prime));

        for (size_t i = 2; i < n; i++)
        {
            if (prime[i])
            {
                for (size_t j = i * 2; j < n; j += i)
                    prime[j] = false;
            }
        }
        int cnt = 0;
        for (size_t i = 2; i < n; i++)
            if (prime[i])
                cnt++;
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.countPrimes(100) << endl;
    return 0;
}
