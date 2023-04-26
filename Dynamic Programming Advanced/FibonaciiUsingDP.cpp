// In Dp arr termed as dp means arr can be written as dp
#include <iostream>
using namespace std;

int fibonacii(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    // recursive case
    return fibonacii(n - 1) + fibonacii(n - 2);
}

// top down

int fiboTopdown(int n, int *arr)
{
    // base case
    if (n == 0 || n == 1)
    {
        return arr[n] = n;
    }

    // calculate krne se phle check krna h ki kahi memopad m already toh nhi h
    if (arr[n] != -1) // agar calculated hoti toh -1 nhi hota
    {
        return arr[n];
    }

    // recursive case
    // return krne se phle store krna h memopad m
    // arr[n]=fiboTopdown(n - 1,arr) + fiboTopdown(n - 2,arr);
    // return arr[n];
    // or
    return arr[n] = fiboTopdown(n - 1, arr) + fiboTopdown(n - 2, arr);
}

// bottom up

int fiboBottomUp(int n)
{
    int *arr = new int[n + 1];
    // bottom up m top down ka jo base case hota h yha intillization conditon bn jata h
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}
int main()
{
    int n;
    cin >> n;
    // int arr[100];
    int *arr = new int[n + 1]; //+1 issliye cuz eg n=5 then we require 6 bucket to store 5 numbers
    // memset(arr,-1,sizeof(arr));
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    cout << "Top down " << fiboTopdown(n, arr) << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Bottom Up " << fiboBottomUp(n) << endl;

    cout << "simple recursion " << fibonacii(n) << endl;
    return 0;
}