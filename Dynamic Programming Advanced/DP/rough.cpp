#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &arr, int indx)
{
    // base case
    if (indx >= arr.size())
    {
        return 0;
    }

    // recursive case
    int include = arr[indx] + solve(arr, indx + 2);
    int exclude = 0 + solve(arr, indx + 1);
    return max(include, exclude);
}
int solveMem(vector<int> &arr, int indx, vector<int> &dp)
{
    // base case
    if (indx >= arr.size())
    {
        return dp[indx] = 0;
    }

    // recursive case
    if (dp[indx] != -1)
    {
        return dp[indx];
    }

    int include = arr[indx] + solveMem(arr, indx + 2, dp);
    int exclude = 0 + solveMem(arr, indx + 1, dp);
    return dp[indx] = max(include, exclude, dp);
}

int solveTab(vector<int> &arr)
{
    vector<int> dp(arr.size() + 1, 0);
    int n = arr.size();
    for (int indx = n - 1; indx >= 0; indx--)
    {
        int include = arr[indx] + dp[indx + 2];
        int exclude = 0 + dp[indx + 1];
        dp[indx] = max(include, exclude, dp);
    }
    return dp[0];
}
int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);

    cout << "Maximum answer is: " << solve(arr, 0) << endl;
    vector<int> dp(arr.size(), -1);
    cout << "Maximum answer using Top down is: " << solveMem(arr, 0, dp) << endl;
    cout << "Maximum answer using Bottom Up is: " << solveTab(arr) << endl;

    return 0;
}