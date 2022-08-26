// https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int stalls[N];

bool min_distance(int dist, int stall, int cow)
{
    int last_pos = 0;
    --cow;

    for (int i = 1; i < stall; ++i)
    {
        if (cow == 0)
        {
            break;
        }
        if (stalls[i] - stalls[last_pos] >= dist)
        {
            --cow;
            last_pos = i;
        }
        }
    return cow == 0;
    // int last_pos = -1;

    // for (int i = 0; i < stall; ++i)
    // {
    //     if (stalls[i] - last_pos >= dist || last_pos == -1)
    //     {
    //         --cow;
    //         last_pos = stalls[i];
    //     }
    //     if (cow == 0)
    //     {
    //         break;
    //     }
    // }
    // return cow == 0;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int stall_num, cow_num;
        cin >> stall_num >> cow_num;
        for (int i = 0; i < stall_num; ++i)
        {
            cin >> stalls[i];
        }
        sort(stalls, stalls + stall_num);
        int low = 0, high = 1e9, mid;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (min_distance(mid, stall_num, cow_num))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (min_distance(high, stall_num, cow_num))
        {
            cout << high << endl;
        }
        else
        {
            cout << low << endl;
        }
    }

    return 0;
}