#include <iostream>
#include <climits>
using namespace std;
// Simple Recursion
int minimumCoinRequired(int *coins, int n, int amount)
{
    // base case
    if (amount == 0)
    {
        return 0; // 0 coin needed hogi agar amount 0 hoga toh
    }

    // recursive case
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) // 1   7   10
    {
        if (amount - coins[i] >= 0) // 15-1 --> 14>=0       15-7 --> 8>=0       15-10 --> 5>=0
        {
            int chotamount = amount - coins[i];                      // 15-1 --> 14             15-7 --> 8              15-10 --> 5
            int chotans = minimumCoinRequired(coins, n, chotamount); // recursion n diya 2      recursion n 2 diya      recursion n 5 diya
            // if ( chotans < ans)                 // 2 < int max             2 < 2                   5<2
            // {
            //     ans = chotans; // 2
            // }
            if (chotans != INT_MAX && chotans < ans)
            {
                ans = chotans; // 2
            }
        }
    }
    return ans + 1; //+1 issliye kyuki 1 coin maine add kra h
}


// Top down
int minimumCoinRequiredTopDown(int *coins, int n, int amount, int *arr)
{
    // base case
    if (amount == 0)
    {
        return arr[amount] = 0; // 0 coin needed hogi agar amount 0 hoga toh
    }

    // calculate krne se phle check ki kahi already calculated toh nhi h
    if (arr[amount] != -1)
    {
        return arr[amount];
    }

    //  recursive case
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) // 1   7   10
    {
        if (amount - coins[i] >= 0) // 15-1 --> 14>=0       15-7 --> 8>=0       15-10 --> 5>=0
        {
            int chotamount = amount - coins[i];                                  // 15-1 --> 14             15-7 --> 8              15-10 --> 5
            int chotans = minimumCoinRequiredTopDown(coins, n, chotamount, arr); // recursion n diya 2      recursion n 2 diya      recursion n 5 diya
            // if ( chotans < ans)                 // 2 < int max             2 < 2                   5<2
            // {
            //     ans = chotans; // 2
            // }
            if (chotans != INT_MAX && chotans < ans)
            {
                ans = chotans; // 2
            }
        }
    }
    // return krne se phle store
    return arr[amount] = ans + 1; //+1 issliye kyuki 1 coin maine add kra h
}

// Bottom Up

int minimumCoinRequiredBottomUp(int *coins, int n, int amount)
{
    int *arr = new int[amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        arr[i] = INT_MAX; // int_max issliye store krwaya kyuki mujhe chahiye minimum coin agar -1 rekh dette toh -1 hi minimum coin hota hmesha which is wrong
    }
    arr[0] = 0; // initialization condition
    for (int rupee = 1; rupee <= amount; rupee++) //rupee=1 || rupee=2
    {
        for (int i = 0; i < n; i++)
        {
            if (rupee - coins[i] >= 0) // 1-1>=0 T  1-7>=0 F || 2-0>=0 T
            {
                int chotamount = rupee - coins[i]; // 1-1->0  || 2-0=2
                arr[rupee] = min(arr[rupee], arr[chotamount] + 1);  // min(intmax,0+1) || min(int max,)
            }
        }
    }

    for (int i = 0; i <= amount; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return arr[amount];
}

int main()
{
    int coins[] = {1, 7, 10};
    // int coins[] = {7,12};    //ish condition ko satify krne k liye line 25 h
    int n = sizeof(coins) / sizeof(int); // total number of elements
    int amount;
    cin >> amount; // 15

    // int arr[100];
    int *arr = new int[amount + 1];
    cout << "Minimum coins required By Simple Recursion " << minimumCoinRequired(coins, n, amount) << endl;

    for (int i = 0; i <= amount; i++)
    {
        arr[i] = -1;
    }

    cout << "Minimum coins required By Top Down " << minimumCoinRequiredTopDown(coins, n, amount, arr) << endl;

    for (int i = 0; i <= amount; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Minimum coins required By Bottom Up " << minimumCoinRequiredBottomUp(coins, n, amount) << endl;
    return 0;
}