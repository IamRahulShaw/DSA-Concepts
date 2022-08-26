// https://codeforces.com/blog/entry/73558

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int workers, days;
    vector<int> workers_bitmask;
    cin >> workers;
    for (int i = 0; i < workers; ++i)
    {
        cin >> days;
        int day_bitmask_num = 0;
        for (int j = 0; j < days; ++j)
        {
            int day;
            cin >> day;
            day_bitmask_num = day_bitmask_num | (1 << day);
        }
        workers_bitmask.push_back(day_bitmask_num);
    }

    int count = -1, person1 = -1, person2 = -1;
    for (int i = 0; i < workers_bitmask.size() - 1; ++i)
    {
        for (int j = i + 1; j < workers_bitmask.size(); ++j)
        {
            if (count <= __builtin_popcount(workers_bitmask[i] & workers_bitmask[j]))
            {
                count = __builtin_popcount(workers_bitmask[i] & workers_bitmask[j]);
                person1 = i;
                person2 = j;
            }
        }
    }

    cout << "person1 is " << person1 << " person2 is " << person2 << " count is " << count << endl;

    return 0;
}