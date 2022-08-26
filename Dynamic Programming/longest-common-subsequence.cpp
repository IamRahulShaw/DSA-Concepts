#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int lcs(int i, int j, string &text1, string &text2)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // we will track on the 0 to i-1 of text1 and whole string of text2
    int ans = lcs(i - 1, j, text1, text2);

    // we will track on the 0 to j-1 of text2 and whole string of text1
    ans = max(ans, lcs(i, j - 1, text1, text2));

    // we will track on the 0 to i-1 of text1 and 0 to j-1 of text2
    ans = max(ans, lcs(i - 1, j - 1, text1, text2) + ((text1[i] == text2[j]) ? 1 : 0)); // If the character matches then we will add 1 or if don't match then add 0;

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    memset(dp, -1, sizeof(dp));
    return lcs(text1.size() - 1, text2.size() - 1, text1, text2);
}

int main()
{
    string text1 = "oxcpqrsvwf", text2 = "shmtulqrypy";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}