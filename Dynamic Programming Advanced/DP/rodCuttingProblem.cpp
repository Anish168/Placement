#include <iostream>
#include <vector>
using namespace std;
int solve(int n, int a, int b, int c)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1e9;
    }

    // recursive case
    int first = solve(n - a, a, b, c);
    int second = solve(n - b, a, b, c);
    int third = solve(n - c, a, b, c);
    return 1 + max(first, max(second, third));
}
int solveMem(int n, int a, int b, int c, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        return dp[n] = 0;
    }
    if (n < 0)
    {
        return dp[n] = -1e9;
    }

    // recursive case
    if (dp[n] != -1)
        return dp[n];
    int first = solve(n - a, a, b, c);
    int second = solve(n - b, a, b, c);
    int third = solve(n - c, a, b, c);
    return dp[n] = 1 + max(first, max(second, third));
}

int solveMem(int nth, int a, int b, int c)
{
    int *arr = new int[nth + 1];
    arr[0] = 0;
    for (int n = 1; n <= nth; n++)
    {
        int first = arr[n - a];
        int second = arr[n - b];
        int third = arr[n - c];
        arr[n] = 1 + max(first, max(second, third));
    }
    return arr[nth];
}

int main()
{
    int n;
    cin >> n;
    int a = 10, b = 11, c = 3;
    int ans = solve(n, a, b, c);
    if (ans <= 0)
    {
        ans = -1;
    }
    cout << "Maximise number of cuts in a rod if it can be cut only in " << ans << endl;
    vector<int> dp(n + 1, -1);
    cout << "Maximise number of cuts in a rod if it can be cut only in " << solveMem(n, a, b, c, dp) << " using TOP DOWN " << endl;
    cout << "Maximise number of cuts in a rod if it can be cut only in " << solveMem(n, a, b, c, dp) << " using BOTTOM UP " << endl;
    return 0;
}