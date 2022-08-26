// https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n], ans[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    stack<int> nge;
    int i = 0;
    while (i < n)
    {
        if (nge.empty())
        {
            nge.push(i);
            ++i;
        }
        else
        {
            if (arr[nge.top()] < arr[i])
            {
                ans[nge.top()] = arr[i];
                nge.pop();
            }
            else
            {
                nge.push(i);
                ++i;
            }
        }
    }
    while (nge.empty() != true)
    {
        ans[nge.top()] = -1;
        nge.pop();
    }
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " " << ans[i] << endl;
    }
    return 0;
}