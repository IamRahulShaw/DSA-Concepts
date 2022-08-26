#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> vec = {1, 4, 2, 9, 12};

    // int max = *max_element(vec.begin(), vec.end());
    // int min = *min_element(vec.begin(), vec.end());
    // int sum = accumulate(vec.begin(), vec.end(), 0);
    // auto it = find(vec.begin(), vec.end(), 2);
    // int countNum = count(vec.begin(), vec.end(), 9);
    // reverse(vec.begin(), vec.end());
    // cout << max << " " << min << " " << sum << " " << *it << " " << countNum << endl;
    // for (int val : vec)
    // {
    //     cout << val << " ";
    // }

    vector<int> vec2 = {1, 5, 7, 9, 13};
    cout << all_of(vec2.begin(), vec2.end(), [](int a)
                   { return a > 0; })
         << endl;
    // auto func = [](int a, int b)
    // { return a + b; }; // Lambda Function.
    // cout << func(2, 9) << endl;
    cout << any_of(vec2.begin(), vec2.end(), [](int a)
                   { return a > 10; })
         << endl;
    cout << none_of(vec2.begin(), vec2.end(), [](int a)
                    { return a > 7; })
         << endl; // there are values which are greater than 7. so it return false
}