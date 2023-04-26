#include <iostream>
#include <string.h> //for using memset
using namespace std;
int elephantWays(int i, int j)
{
    // base case
    if (i == 0 && j == 0)
    {
        return 1;
    }

    // recursive case
    int ans = 0;
    for (int k = 0; k < i; k++) // colums ka sum nikalenge phle
    {
        ans = ans + elephantWays(k, j); // j=2 and k will varies from 0 to 2
    }
    for (int k = 0; k < j; k++)
    {
        ans = ans + elephantWays(i, k); // i=3 and j will varies from 0 to 2
    }
    return ans;
}

// TOP DOWN

int elephantWaysTopDown(int i, int j, int arr[][100])
{
    // base case
    if (i == 0 && j == 0)
    {
        // return krne se phle store
        return arr[i][j] = 1;
    }
    // calculate krne se phle check
    if (arr[i][j] != -1)
    {
        return arr[i][j];
    }

    // recurisve case
    int ans = 0;
    for (int k = 0; k < i; k++) // colums ka sum nikalenge phle
    {
        ans = ans + elephantWaysTopDown(k, j, arr); // j=2 and k will varies from 0 to 2
    }
    for (int k = 0; k < j; k++)
    {
        ans = ans + elephantWaysTopDown(i, k, arr); // i=3 and j will varies from 0 to 2
    }
    return arr[i][j] = ans;
}

// Bottom Up
int elephantWaysBottomUp(int i, int j) // i=3 j=2
{
    // base case intilization condition bn jata h
    int dp[100][100] = {0};

    // har index pr iterate krna h or calculate krna h
    for (int l = 0; l <= i; l++) // 0<=3
    {
        for (int m = 0; m <= j; m++) // 0<=2  1<=2
        {
            // base case intilization condition bn jata h
            int ans = 0;
            if (l == 0 && m == 0)
            {
                dp[l][m] = {1};
            }
            // now humhe ush index ki calculation k liye uppr coloum ko and row ko add krna hoga
            else
            {
                // column
                for (int k = 0; k < i; k++) // 0<3
                {
                    ans = ans + dp[k][m];
                }
                // row
                for (int k = 0; k < j; k++) // 0<2
                {
                    ans = ans + dp[l][k];
                }
                dp[l][m] = ans;
            }
        }
    }
    for (int l = 0; l <= i; l++)
    {
        for (int m = 0; m <= j; m++)
        {
            cout << dp[l][m] << " ";
        }
        cout << endl;
    }
    return dp[i][j];
}

int main()
{
    int i, j;
    cin >> i >> j; // destination 2,3
    cout << "No. of ways to reach that destination By Simple Recursion " << elephantWays(i, j);
    cout << endl;
    int arr[100][100];
    memset(arr, -1, sizeof(arr));
    cout << "No. of ways to reach that destination By Top Down Approch " << elephantWaysTopDown(i, j, arr);
    cout << endl;
    for (int l = 0; l <= i; l++)
    {
        for (int m = 0; m <= j; m++)
        {
            cout << arr[l][m] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "No. of ways to reach that destination By Bottom Up Approch " << elephantWaysBottomUp(i, j);

    return 0;
}