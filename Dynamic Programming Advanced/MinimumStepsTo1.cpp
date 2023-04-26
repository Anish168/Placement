#include <iostream>
#include <climits>
using namespace std;

// simple recursion
int minimunsteps(int n)
{
    // base case
    if (n == 1) // 1 se lekr 1 tk jane m 0 steps
    {
        return 0;
    }

    // recursive case;
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX; // infinity se intilize kr diya cuz humhe minimum steps lena h so kuch bhi number aaye wo toh infinity se chota hi hoga
    op1 = minimunsteps(n - 1); // suppose 3 dega means 3 steps lge ushko 1 tk reach krne m subtract k through
    if (n % 3 == 0)            // phle mai check krunga ki divide ho rha h 3 se
    {
        op2 = minimunsteps(n / 3); // ab mai recursion ko dunga, suppose 5 dega means 5 steps lge ushko 1 tk reach krne m division by 3 k through
    }

    if (n % 2 == 0) // phle mai check krunga ki divide ho rha h 2 se
    {
        op3 = minimunsteps(n / 2); // ab mai recursion ko dunga, suppose 5 dega means 5 steps lge ushko 1 tk reach krne m division by 2 k through
    }

    return min(op1, min(op2, op3)) + 1; // ab uppr jitne steps lge un m se minimum and +1 cuz ek step maine bhi toh kiya
}

// Top down
int minimunstepsTopdown(int n, int *arr)
{
    // base case
    if (n == 1) // 1 se lekr 1 tk jane k 0 steps
    {
        return arr[n] = 0;
    }

    // calculate krne se phle check
    if (arr[n] != -1)
    {
        return arr[n];
    }

    // recursive case;
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    op1 = minimunstepsTopdown(n - 1, arr);
    if (n % 3 == 0)
    {
        op2 = minimunstepsTopdown(n / 3, arr);
    }

    if (n % 2 == 0)
    {
        op3 = minimunstepsTopdown(n / 2, arr);
    }

    // return krne se phle store
    return arr[n] = min(op1, min(op2, op3)) + 1; //+1 cuz ek step maine bhi toh kiya
}

// Bottom Up
int minimunstepsBootomUp(int n)
{
    int *arr = new int[n + 1];
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        op1 = arr[i - 1];
        if (i % 2 == 0)
        {
            op2 = arr[i / 2];
        }
        if (i % 3 == 0)
        {
            op3 = arr[i / 3];
        }
        arr[i] = min(op1, min(op2, op3)) + 1;
    }
    return arr[n];
}
int main()
{
    int n;
    cin >> n; // always greater than 0
    int *arr = new int(n + 1);
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    cout << "Minimum steps to reach 1 is by Simple Recursion " << minimunsteps(n) << endl;

    cout << "Minimum steps to reach 1 is by Top down " << minimunstepsTopdown(n, arr) << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Minimum steps to reach 1 is by Bottom Up " << minimunstepsBootomUp(n) << endl;

    return 0;
}