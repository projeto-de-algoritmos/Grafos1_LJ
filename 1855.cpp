#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;

using namespace std;

const int N = 123;
char grid[N][N];
int m, n;

map<char, int> mp;


bool dfs(int x, int y, int dir) {
    //verifica se um báu foi encontrado
    if(grid[x][y] == '*') {
        return true;
    }
    //verifica se a posição atual já foi visitada ou se ela saiu do caminho
    if(grid[x][y] == 'X' or !grid[x][y]) {
        return false;
    }
    
    return dfs(u, v, dir);
}

int main() {
    
    mp['^'] = 0;
    mp['>'] = 1;
    mp['v'] = 2;
    mp['<'] = 3;
    
    memset(grid, 0, sizeof grid);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%s", &grid[i][1]);
    }

    return 0;
}
