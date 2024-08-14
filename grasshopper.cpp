#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int dist[101][101];
int visited[101][101];
vector<ii> moves;
int n=100;
int h, w, xi, yi, xf, yf;

bool isValid(int x, int y, int sta) {
    if(x>0 and x<=n and y>0 and y<=n) {
        if(!visited[x][y]) {
            return true;
        }
    }
    return false;
}

void bfs() {
    queue<ii> q;
    q.push({1,1});
    visited[1][1] = 1;
    dist[1][1] = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.first;

        for(auto &[dx, dy]: moves) {
            int u=x+dx, v=y+dy;
            if(isValid(u, v, 0)) {
                q.push({u,v});
                visited[u][v] = true;
                dist[u][v] = dist[x][y] + 1;
            }
        }
    }
}

void solve() {
    int x, y;
    x = abs(xf-xi)+1;
    y = abs(yf-yi)+1;

    int ans;

    if(h == 1 or w == 1) {
        ans = -1;
    }

    else if(h == 2 or w == 2) {
        if((x == 1 and y%4 == 1) or (x == 2 and y%4 == 3)) {
            ans = -1;
        }
        if((y == 1 and x%4 == 1) or (y == 2 and x%4 == 3)) {
            ans = -1;
        }
    }

    else if(h == 3 and w == 3) {
        if(x == 2 and y == 2) {
            ans = -1;
        }
        
    }

    if((h>=5 and w>=4) or (h>=4 and w>=5)) {
        if(x == 2 and y == 2 and !(xi == 1 and yi == 1) and !(xf == 1 and yf == 1))
            ans = dist[x][y];
        else
            ans = 2;
    }



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    moves = {{-2,1}, {2, 1}, {-2, -1},
            {2, -1}, {1, -2}, {1,2},
            {-1, -2}, {-1,2}};

    memset(visited, 0, sizeof visited);
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    bfs();

    while(cin >> h >> w >> xi >> yi >> xf >> yf) {
        solve();
    }
    return 0;
}