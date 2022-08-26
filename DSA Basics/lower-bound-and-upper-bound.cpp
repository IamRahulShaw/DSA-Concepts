#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> vec;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     int num;
    //     cin >> num;
    //     vec.push_back(num);
    // }
    // sort(vec.begin(), vec.end());
    // int val;
    // cin >> val;
    // auto it_lower_bound = lower_bound(vec.begin(), vec.end(), val);
    // auto it_upper_bound = upper_bound(vec.begin(), vec.end(), val);
    // cout << "lower bound of " << val << " is " << (it_lower_bound == vec.end() ? -1 : *it_lower_bound) << endl;
    // cout << "upper bound of " << val << " is " << (it_upper_bound == vec.end() ? -1 : *it_upper_bound) << endl;

    map<int, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int key, val;
        cin >> key >> val;
        m[key] = val;
    }
    int key;
    cin >> key;
    auto it_lower_bound = m.lower_bound(key);
    auto it_upper_bound = m.upper_bound(key); // inbuilt lower bound function have the timecomplexity of O(n) for map and sets, so we have to use the member upper_bound and lower_bound functions of maps and sets
    cout << "lower bound of " << key << " is " << (it_lower_bound == m.end() ? -1 : it_lower_bound->second) << endl;
    cout << "upper bound of " << key << " is " << (it_upper_bound == m.end() ? -1 : it_upper_bound->second) << endl;

    return 0;
}