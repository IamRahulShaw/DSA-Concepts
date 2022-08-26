// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/
#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c)
{
    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

vector<string> vowel_combinations(set<char> vowels)
{
    vector<char> vowels_vector;
    for (auto val : vowels)
    {
        vowels_vector.push_back(val);
    }
    vector<string> ans;
    int vowels_size = vowels.size();
    int sz = 1 << vowels.size();
    for (int mask = 1; mask < sz; ++mask)
    {
        string s;
        for (int j = 0; j < vowels_size; ++j)
        {
            if (mask & (1 << j))
            {
                s.push_back(vowels_vector[j]);
            }
        }
        ans.push_back(s);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> names;
        for (int i = 0; i < n; ++i)
        {
            string name;
            cin >> name;
            names.push_back(name);
        }
        int names_size = names.size();
        map<string, int> combinations_map;
        for (int i = 0; i < names_size; ++i)
        {
            set<char> vowels;
            for (auto c : names[i])
            {
                if (is_vowel(c))
                {
                    vowels.insert(c);
                }
            }
            vector<string> combinations = vowel_combinations(vowels);
            for (auto val : combinations)
            {
                combinations_map[val]++;
            }
        }
        long long count = 0;
        for (auto pair : combinations_map)
        {
            long long n = pair.second;
            if (n >= 3)
            {
                long long num_ways = (n * (n - 1) * (n - 2)) / 6;
                if (((pair.first).size()) % 2 == 0)
                {
                    count = count - num_ways;
                }
                else
                {
                    count = count + num_ways;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}