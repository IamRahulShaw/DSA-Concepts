#include <bits/stdc++.h>
using namespace std;

const int Num_Max = 2e5 + 10;
vector<int> multiples(Num_Max); // We make a multiples array to pre-compute and store the total number of multiples of a number present in the array
vector<int> hsh_count(Num_Max);

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        hsh_count[num]++; // We store the count of the numbers
    }
    for (int i = 1; i < Num_Max; ++i)
    {
        for (int j = i; j < Num_Max; j = j + i)
        {
            multiples[i] = multiples[i] + hsh_count[j]; // hsh_count[j] tells the total number of j present in the array. Thus we store the total number of multiples present in the array
        }
    }

    int T, P, Q;
    cin >> T;
    while (T--)
    {
        cin >> P >> Q;
        int P_Multiples = multiples[P];
        int Q_Multiples = multiples[Q];
        long long LCM_P_Q = ((P * 1LL * Q) / __gcd(P, Q));
        int result = P_Multiples + Q_Multiples;
        if (LCM_P_Q < Num_Max)
        {
            result = result - multiples[LCM_P_Q];
        }
        cout << result << endl;
    }

    return 0;
}