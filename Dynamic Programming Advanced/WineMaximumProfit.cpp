#include <iostream>
using namespace std;
int wineproblem(int *price, int left, int right, int day)
{
    // base case
    if (left > right) // jab left right ko overshoot kr jyga toh max profit 0 hoga it means sb bottle cover ho gyi h ab koi bottle exit nhi krta
    {
        return 0;
    }

    // recursive case
    int op1 = price[left] * day + wineproblem(price, left + 1, right, day + 1);
    int op2 = price[right] * day + wineproblem(price, left, right - 1, day + 1);
    return max(op1, op2);
}

// Top down
int wineproblemTop(int *price, int left, int right, int day, int arr[100][100])
{
    // base case
    if (left > right) // jab left right ko overshoot kr jyga toh max profit 0 hoga it means sb bottle cover ho gyi h ab koi bottle exit nhi krta
    {
        return arr[left][right] = 0;
    }

    if (arr[left][right] != -1)
    {
        return arr[left][right];
    }

    // recursive case
    int op1 = price[left] * day + wineproblemTop(price, left + 1, right, day + 1, arr);
    int op2 = price[right] * day + wineproblemTop(price, left, right - 1, day + 1, arr);
    return arr[left][right] = max(op1, op2);
}

// Bottom up
int wineproblemBottom(int *price, int left, int right, int day, int n)
{
    int dp[100][100] = {0};
    // diagonal fill kr rhe h
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = n * price[i];
    }

    // for combination bottles or remaining bottles after diagonal bottel sold out

    for (int i = n - 2; i >= 0; i--) // i represent here left(row)  //3
    {
        for (int j = 0; j < n; j++) // j represent here right(column)   //0
        {
            if (i < j) // agar humara row<column h tbhi     //3<0 F 3<1 F 3<2 F 3<3 F 3<4 T
            {
                int day = n - (j - i);                   // day= 5-(4-3)
                int op1 = day * price[i] + dp[i + 1][j]; // 4*1+dp[4][4]
                int op2 = day * price[j] + dp[i][j - 1]; // 4*4+dp[3][3]
                dp[i][j] = max(op1, op2);                // dp[3][4]=24
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return dp[0][n - 1]; // last m hoga maximum profit dp[0,4] pr
}

int main()
{
    int price[] = {2, 3, 5, 1, 4};
    int n = sizeof(price) / sizeof(int);
    cout << "Maximum Profit by Simple Recursion " << wineproblem(price, 0, n - 1, 1) << endl; // wineproblem(price,left,right,day)

    int arr[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            arr[i][j] = -1;
        }
    }

    cout << "Maximum Profit by Top Down " << wineproblemTop(price, 0, n - 1, 1, arr) << endl; // wineproblem(price,left,right,day,arr)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Maximum Profit by Bottom Up " << wineproblemBottom(price, 0, n - 1, 1, n) << endl; // wineproblem(price,left,right,day,arr)

    return 0;
}