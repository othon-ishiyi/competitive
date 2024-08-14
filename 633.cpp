#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int dist[41][41][3];
int visited[41][41][3];
vector<ii> moves[2];
int n;
ii start, dest;


bool isValid(int x, int y, int sta) {
    if(x>0 and x<=n and y>0 and y<=n) {
        if(!visited[x][y][sta]) {
            return true;
        }
    }
    return false;
}

void bfs() {
    for(int i=0; i<3; i++) {
        dist[start.first][start.second][i] = 0;
        visited[start.first][start.second][i] = 1;
    }
    queue<pair<ii, int>> q;
    q.push({start, -1});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int status = cur.second;

        if(status != 0) {
            for(auto &[dx, dy]: moves[0]) {
                int u=x+dx, v=y+dy;
                if(isValid(u, v, 0)) {
                    q.push({{u,v}, 0});
                    visited[u][v][0] = true;
                    if(status == -1)
                        dist[u][v][0] = 1;
                    else
                        dist[u][v][0] = dist[x][y][status] + 1;
                }
            }
        }
        if(status != 1) {
            for(auto &[dx, dy]: moves[1]) {
                int u=x+dx, v=y+dy;
                if(isValid(u, v, 1)) {
                    q.push({{u,v},1});
                    visited[u][v][1] = true;
                    if(status == -1)
                        dist[u][v][1] = 1;
                    else
                        dist[u][v][1] = dist[x][y][status] + 1;
                } 
            }
        }
        if(status != 2) {
            int u = n-x+1, v = n-y+1;
            if(isValid(u, y, 2)) {
                q.push({{u,y},2});
                visited[u][y][2] = true;
                if(status == -1)
                    dist[u][y][2] = 1;
                else
                    dist[u][y][2] = dist[x][y][status] + 1;
            }
            if(isValid(x, v, 2)) {
                q.push({{x,v},2});
                visited[x][v][2] = true;
                if(status == -1)
                    dist[x][v][2] = 1;
                else
                    dist[x][v][2] = dist[x][y][status] + 1;
            }
        }
    
    }
}

void solve() {
    moves[0] = {{-2,1}, {2, 1}, {-2, -1},
                {2, -1}, {1, -2}, {1,2},
                {-1, -2}, {-1,2}};
    moves[1] = {{-2,-2}, {-2, 2}, {2,-2}, {2,2}};

    cin >> start.first >> start.second >> dest.first >> dest.second;
    memset(visited, 0, sizeof visited);
    for(int i=0; i<41; i++) {
        for(int j=0; j<41; j++) {
            for(int k=0; k<3; k++) {
                dist[i][j][k] = INT_MAX;
            }
        }
    }
    int a, b;
    while(cin >> a >> b) {
        if(a == 0) break;
        for(int k=0; k<3; k++) {
            visited[a][b][k] = 1;
        }
    }

    bfs();

    int ans = INT_MAX;
    for(int i=0; i<3; i++) {
        ans = min(ans, dist[dest.first][dest.second][i]);
    }

    if(ans == INT_MAX) {
        cout << "Solution doesn't exist\n";
    }
    else {
        cout << "Result : " << ans << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n) {
        if(n == 0) break;
        n *= 2;
        solve();
    }
    return 0;
}