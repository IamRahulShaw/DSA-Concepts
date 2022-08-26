#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> symbols = {{'(', 0}, {'{', 1}, {'[', 2}, {')', 0}, {'}', 1}, {']', 2}};

string isBalanced(string s)
{
    stack<char> bracket;
    for (char c : s)
    {
        if (c == ')' || c == '}' || c == ']')
        {
            if (bracket.empty())
            {
                return "NO";
            }
            else
            {
                if (symbols[bracket.top()] == symbols[c])
                {
                    bracket.pop();
                }
                else
                {
                    return "NO";
                }
            }
        }
        else
        {
            bracket.push(c);
        }
    }
    return (bracket.empty()) ? "YES" : "NO";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    return 0;
}