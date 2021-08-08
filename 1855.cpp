#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;

using namespace std;

const int N = 123;
char grid[N][N];
int m, n;

int main() {
    memset(grid, 0, sizeof grid);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%s", &grid[i][1]);
    }

    return 0;
}
