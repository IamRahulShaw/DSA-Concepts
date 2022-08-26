// https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, multiset<string>> marks;
    for (int i = 0; i < n; ++i)
    {
        int number;
        string name;
        cin >> name >> number;
        auto it = marks.find(number);
        marks[number].insert(name);
    }
    for (auto it = marks.rbegin(); it != marks.rend(); ++it)
    {
        for (auto val : it->second)
        {
            cout << val << " " << it->first << endl;
        }
    }
    return 0;
}