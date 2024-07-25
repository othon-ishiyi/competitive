
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<ii> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
string grid[51];
int visited[51][51];

int n, m;
int cnt = 0;

void dfs(int x, int y) {
    visited[x][y] = 1;
    if(grid[x][y] == 'G') {
        cnt++;
    }

    for(auto &[i, j] : moves) {
        int u = x+i, v = y+j;
        if(grid[u][v] == 'T') {
            return;
        }
    }

    for(auto &[i, j] : moves) {
        int u = x+i, v = y+j;
        if(grid[u][v] != '#' and !visited[u][v]) {
            dfs(u, v);
        }
    }

}

void solve() {
    memset(visited, 0, sizeof visited);

    cin >> m >> n;

    int x, y;

    for(int i=0; i<n; i++) {
        cin >> grid[i];
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'P') {
                x = i;
                y = j;
            }
        }
    }

    dfs(x, y);
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}