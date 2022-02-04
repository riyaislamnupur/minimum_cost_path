#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 4

int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] +
         min(minCost(cost, m - 1, n - 1),
             minCost(cost, m - 1, n),
             minCost(cost, m, n - 1));
}

int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int main()
{
    int cost[R][C] = { { 3, 5, 7, 10 },
                       { 6, 4, 3, 9 },
                       { 6, 5, 4, 5 } };

    cout << minCost(cost, 2, 3) << endl;

    return 0;
}
