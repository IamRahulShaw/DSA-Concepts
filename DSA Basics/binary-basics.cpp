#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << INT_MAX << endl;
    // int a = (1 << 32) - 1; // here 1 is an integer and left shift 32 is caused 33 bits to create 2^32 in decimal. but, integer has only 32 bits, so here is a overflow warning
    // int a = (1LL << 32) - 1; // here we make 1 is a long long which have 64 bits. so, no warning
    // cout << a << endl; // but still overflow happens, print -1, because this integer is a signed int, so it has 31 bits for value and 1 for sign
    int a = (1LL << 31) - 1;
    cout << a << endl;                // it is equal to INT_MAX
    unsigned int b = (1LL << 32) - 1; // unsigned int has total 32 bits for value, no bit for sign, so it can store this value
    cout << b << endl;
    return 0;
}