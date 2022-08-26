#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    // we print binary here for 32 bits, means from 32th bit to 0th bit
    for (int i = 31; i >= 0; --i)
    {
        cout << ((num >> i) & 1); // we right shift the numbet to the first position. Let say, if i is 3 then num >> i will take the 3th bit of the number to 0th bit. then we '&' the number with 1. so, the other bits right side of 0th position will automatically be 0 because we make '&' with ...000000001, so other bits automatically be zero and if 0th bit will 0 then '&' with 1 is 0, otherwise 1. Thus, the number printed.
    }
    cout << endl;
}

int main()
{
    int a = 5;
    // printBinary(a);

    // set a bit
    // printBinary(a | (1 << 4)); // set a bit at 4th position

    // unset a bit
    // printBinary(a & (~(1 << 2))); // unset a bit at 2nd position

    // toggle a bit
    // printBinary(a ^ (1 << 5)); // toggle a bit at 5th position

    // count bits (means count set bits)
    int b = 255;
    int count = 0;
    for (int i = 31; i >= 0; --i)
    {
        // if ((b >> i) & 1)
        // {
        //     ++count;
        // }
        // or
        if (b & (1 << i))
        {
            ++count;
        }
    }
    cout << count << endl;
    cout << __builtin_popcount(b) << endl;                 // inbuilt function for counting set bits for integers
    cout << __builtin_popcountll((1LL << 35) - 1) << endl; // 35s one. integer can not store above 31th bit, so we use __builtin_popcountll it is for long long.
    printBinary(b);

    return 0;
}