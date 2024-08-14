#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[101];
int visited[101];
int parent[101];
int explore[101];
int min_value[101];
int art[101];
int n;
int idx;
int root_children;

void articulation(int i) {
    visited[i] = 1;
    explore[i] = idx++;
    min_value[i] = explore[i];
    for(int v: g[i]) {
        if(visited[v] and v != parent[i]) {
            min_value[i] = min(min_value[i], explore[v]);
        }
        if(!visited[v]) {
            if(i == 1) root_children++;
            parent[v] = i;
            articulation(v);
            min_value[i] = min(min_value[i], min_value[v]);
            if(explore[i] <= min_value[v])
                art[i] = true;
        }
    }
}

void solve() {
    memset(visited, 0, sizeof visited);
    memset(parent, -1, sizeof parent);
    memset(art, 0, sizeof art);
    for(auto &v: g) {
        v.clear();
    }
    idx = 0;
    cin.ignore();
    while(true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        ss >> v;
        if(v == 0) break;
        int a;
        while(ss >> a) {
            g[v].push_back(a);
            g[a].push_back(v);
        }
    }
    int ans = 0;
    root_children = 0;
    articulation(1);
    for(int i=0; i<101; i++) {
        ans += art[i];
    }
    cout << ans-(root_children == 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        cin >> n;
        if(n == 0) break;
        solve();
    }
    return 0;
}