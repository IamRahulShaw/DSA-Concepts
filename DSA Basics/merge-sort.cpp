//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int left_loop_size = (m - l) + 1;
        int right_loop_size = r - (m + 1) + 1;
        int L[left_loop_size + 1], R[right_loop_size + 1];
        for (int i = 0; i < left_loop_size; i++)
        {
            L[i] = arr[i + l];
        }
        for (int i = 0; i < right_loop_size; i++)
        {
            R[i] = arr[i + m + 1];
        }
        L[left_loop_size] = R[right_loop_size] = INT_MAX;
        for (int i = 0, j = 0, k = l; k <= r; k++)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // code here
        if (l == r)
        {
            return;
        }
        int m = (r + l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends