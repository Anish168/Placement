#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> val, vector<int> wt, int capacity, int indx)
{
    // base case
    if (indx == val.size() || capacity == 0)
    {
        return 0;
    }

    int include = 0;
    if (capacity >= wt[indx])
    {
        include = val[indx] + solve(val, wt, capacity - wt[indx], indx + 1);
    }
    int exclude = 0 + solve(val, wt, capacity, indx + 1);
    return max(include, exclude);
}

int solveMem(vector<int> val, vector<int> wt, int capacity, int indx, vector<vector<int>> &dp)
{
    // base case
    if (indx == val.size() || capacity == 0)
    {
        return dp[indx][capacity] = 0;
    }

    if (dp[indx][capacity] != -1)
    {
        return dp[indx][capacity];
    }
    int include = 0;
    if (capacity >= wt[indx])
    {
        include = val[indx] + solve(val, wt, capacity - wt[indx], indx + 1);
    }
    int exclude = 0 + solve(val, wt, capacity, indx + 1);
    return dp[indx][capacity] = max(include, exclude);
}
int main()
{
    int n = 3;
    vector<int> val(n), wt(n);
    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);
    int capacity = 50;
    int indx = 0;
    cout << "Maximum profit that can be obtain by simple recursion: " << solve(val, wt, capacity, indx) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    cout << "Maximum profit that can be obtain by TOP DOWN: " << solveMem(val, wt, capacity, indx, dp) << endl;

    return 0;
}