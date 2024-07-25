
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<ii> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
string grid[20];
int visited[20][20];

int n, m;
int xi, yi;
int cnt = 0;

char continent;

bool valid(int x, int y) {
    if(x >= 0 and x < m and y >=0 and y<n) {
        if(grid[x][y] == continent) {
            if(!visited[x][y]) 
                return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    visited[x][y] = 1;

    if(x == xi and y == yi) {
        cnt = INT_MIN;
    }

    for(auto &[i, j] : moves) {
        int u = x+i, v = (y+j)%n;
        if(v == -1) v += n;
        if(valid(u, v)) {
            dfs(u, v);
        }
    }
    
    cnt++;
}

void solve() {
    memset(visited, 0, sizeof visited);
    for(auto &s: grid) s.clear();

    for(int i=0; i<m; i++) {
        cin >> grid[i];
    }

    cin >> xi >> yi;

    continent = grid[xi][yi];

    int ans = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(valid(i, j)) {
                cnt = 0;
                dfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> m >> n){
        solve();
    }
    return 0;
}