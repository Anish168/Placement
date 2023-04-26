#include <iostream>
using namespace std;
int solve(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int ans = solve(n - 1) + solve(n - 2);
    return ans;
}

// Rec + mem
// Step 1:- create dp array + pass in function
// Step 2:- store the ans in dp is array
// Step 3:- check if dp array already has answer, if yes, then return\just after base case

int solve(int n, int *arr)
{
    // base case
    if (n == 0)
    {
        return arr[n] = 0;
    }
    if (n == 1)
    {
        return arr[n] = 1;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int ans = solve(n - 1) + solve(n - 2);
    return arr[n] = ans;
}

// //Bottom Up
// step1:- dp array creation
// Step 2:- base case analysis of rec code and update dp array accordingly
// Step 3:- find the range for the changing variable and copy paste the logic in rec code accordingly
int solveTab(int nthTerm)
{
    // step 1: dp array create
    int *arr = new int[nthTerm + 1];
    // step 2:- base case and update dp array
    arr[0] = 0;
    arr[1] = 1;

    // step 3: -find range and copy paste
    for (int n = 2; n <= nthTerm; n++)
    {
        int ans = arr[n - 1] + arr[n - 2];
        arr[n] = ans;
    }
    return arr[nthTerm];
}

// space optimization
int solveSO(int nth)
{
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    for (int n = 2; n <= nth; n++)
    {
        curr = prev1 + prev2;
        // curr = ans;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;
    // int ans = solve(n);
    // cout << "ans is: " << ans << endl;
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    // int ans = solve(n);
    // int ans = solve(n, arr);
    int ans = solveSO(n);
    cout << "ans is: " << ans << endl;
}