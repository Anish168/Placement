#include <iostream>
#include <climits>
using namespace std;
// Simple Recursion
int minCost(int cost[4][4], int i, int j)
{
    // base case
    if (i == 0 && j == 0)
    {
        return cost[i][j]; // return kro i=0 and j=0 pr jo value cuz whi hmara source h na whi se toh start krn h i.e 2
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX; // int max issliye return kr rhe h kyuki ek time pr i ki value hogi -1 decrease kr rhi h na hum i ko
                        // so ab -1 toh koi valid path hoga nhi so wha se aane k path 0 hoga but 0 le nhi skte kyuki humhe minimum chahiye
                        // 0 lenge toh har time 0 hi minimum path hoga which is wrong so intmax return kr rhe h
    }

    // recursive case
    // int op1 = minCost(cost, i - 1, j) + cost[i][j];  //yha wrap around ho rha so ans negative aa rha h kyuki hum ushme cost add kr rhe h
    // int op2 = minCost(cost, i, j - 1) + cost[i][j];

    int op1 = minCost(cost, i - 1, j);
    int op2 = minCost(cost, i, j - 1);
    return min(op1, op2) + cost[i][j];
}

// Top down
int minCostTopdown(int cost[4][4], int i, int j, int arr[4][4])
{
    // base case
    if (i == 0 && j == 0)
    {
        return arr[i][j] = cost[i][j];
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (arr[i][j] != -1)
    {
        return arr[i][j];
    }

    // reursive case
    int op1 = minCostTopdown(cost, i - 1, j, arr);
    int op2 = minCostTopdown(cost, i, j - 1, arr);
    return arr[i][j] = min(op1, op2) + cost[i][j];
}

// Bottom Up
int minCostBottomUp(int cost[4][4], int i, int j)
{
    int arr[100][100];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // top down ka base case bottom up m intialization condition hoti h
            if (i == 0 && j == 0)
            {
                arr[i][j] = cost[i][j];
            }
            else if (i == 0)
            {
                arr[i][j] = cost[i][j] + arr[i][j - 1];
            }
            else if (j == 0)
            {
                arr[i][j] = cost[i][j] + arr[i - 1][j];
            }
            else
            {
                arr[i][j] = min(arr[i - 1][j], arr[i][j - 1]) + cost[i][j];
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return arr[i][j];
}
int main()
{
    int cost[4][4] = {
        {2, 1, 3, 4},
        {3, 1, 1, 10},
        {1, 6, 1, 1},
        {2, 7, 4, 3},
    };
    // destination is 2,3
    cout << "Minimum Cost Path by simple Recursion " << minCost(cost, 2, 3) << endl;

    int arr[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = -1;
        }
    }
    cout << "Minimum Cost Path by Top Down " << minCostTopdown(cost, 2, 3, arr) << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Minimum Cost Path by Bottom Up " << minCostBottomUp(cost, 2, 3) << endl;

    return 0;
}