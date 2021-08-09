#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;

using namespace std;

const int N = 123;
char grid[N][N];
int m, n;
typedef pair<int, int> ii;
//Array de pairs que define como uma direção mp[] deve se comportar
const ii XY[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
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
    
    auto at = mp.find(grid[x][y]);
    if(at != mp.end()) {
        dir = at->second;
    }
    
    //marca uma posição como visitada
    grid[x][y] = 'X';
    //percorre as linhas de acordo com a direção
    int u = x + XY[dir].first;
    //percorre as colunas de acordo com a direção
    int v = y + XY[dir].second;
    
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
    
    bool ans = dfs(1, 1, mp[grid[1][1]]);
    printf("%s\n", ans ? "*" : "!");
    return 0;
}
