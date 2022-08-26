#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 31; i >= 0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{

    // int num = 17;

    // odd & even check
    // if (num & 1)
    // {
    //     cout << num << " is a odd number" << endl;
    // }
    // else
    // {
    //     cout << num << " is a even number" << endl;
    // }

    // Multiply by 2 and divide by 2
    // cout << (num >> 1) << " is " << num << "/2" << endl;
    // cout << (num << 1) << " is " << num << "*2" << endl;

    // Binary representation of uppercase and lowercase
    // for (char c = 'A'; c <= 'D'; c++)
    // {
    //     cout << c << endl;
    //     printBinary((int)c);
    // }
    // for (char c = 'a'; c <= 'd'; c++)
    // {
    //     cout << c << endl;
    //     printBinary((int)c);
    // }

    // uppercase to lowercase
    // char A = 'A';
    // char a = char(A | (1 << 5));
    // cout << char(1 << 5) << endl; // space
    // char a = char(A | ' ');
    // cout << a << endl;

    // char d = 'd';
    // char D = char(d & ~(1 << 5));
    // char D = char(d & ((1 << 7) - 1) & (~(1 << 5)));
    // cout << char(((1 << 7) - 1) & (~(1 << 5))) << endl; // underscore _
    // char D = char(d & '_');
    // cout << D << endl;

    // clearing all the lsb after ith bit and msb before ith bit
    int val = 30;
    printBinary(val);
    printBinary(val & (~((1 << 2) - 1))); // clearing all LSB after 2th bit
    // printBinary(val & ((1 << (2 + 1)) - 1)); // clearing all msb before 2th bit

    // Check a number is power of 2 or not
    // int num = 14;
    // printBinary(num);
    // if (num & (num - 1))
    // {
    //     cout << num << " is not power of 2" << endl;
    // }
    // else
    // {
    //     cout << num << " is power of 2" << endl;
    // }
}