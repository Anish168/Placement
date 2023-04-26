#include <iostream>
using namespace std;
// Simple Recursion
int n_staircase(int stair, int max)
{
    // base case
    if (stair == 0)
    {
        return 1;
    }
    if (stair < 0)
    {
        return 0;
    }

    // recursive case
    int sum = 0;
    for (int i = 0; i <= max; i++)
    {
        sum = sum + n_staircase(stair - i, max);
    }
    cout << "ways is";
    return sum;
}

// Top down
int n_staircaseTopdown(int stair, int max, int *arr)
{
    // base case
    if (stair == 0)
    {
        return arr[stair] = 1;
    }
    if (stair < 0)
    {
        return 0; // agar stair ki value 0 se choti hui toh store krne ki zarrorat hi nhi h cuz steps can't be negative
    }

    if (arr[stair] != -1)
    {
        return arr[stair];
    }

    // recursive case
    int sum = 0;
    for (int i = 0; i <= max; i++)
    {
        sum = sum + n_staircaseTopdown(stair - i, max, arr);
    }
    cout << "ways is";
    return arr[stair] = sum;
}
int main()
{
    int stair; // n=4
    cin >> stair;
    int max;
    cin >> max;
    cout << "Number of ways that child can reach to his mother " << n_staircase(stair, max) << endl;
    cout << endl;
    int arr[100];
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    cout << "Number of ways that child can reach to his mother " << n_staircaseTopdown(stair, max, arr) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
