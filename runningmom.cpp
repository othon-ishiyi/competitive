// Simpler solution at builddeps2.cpp

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define explored 1
#define done 2


vi g[10010];
int visited[10010];
int hasCycle[10010];
int n;

bool dfs(int i) {
    if(visited[i] == done) {
        return hasCycle[i];
    }
    visited[i] = explored;

    for(int v: g[i]) {
        if(visited[v] == explored) {
            hasCycle[i] = true;
        }
        else if(dfs(v)) hasCycle[i] = true;
    }

    visited[i] = done;

    return hasCycle[i];
}

void solve() {
    unordered_map<string, int> m;
    memset(visited, 0, sizeof visited);
    memset(hasCycle, 0, sizeof hasCycle);

    cin >> n;
    int idx = 0;

    for(int i=0; i<n; i++) {
        string a, b;
        cin >> a >> b;

        if(!m.count(a)) {
            m.insert({a, idx++});
        }

        if(!m.count(b)) {
            m.insert({b, idx++});
        }
        g[m[a]].push_back(m[b]);

    }

    string s;
    while(cin >> s) {
        cout << s << ' ';
        if(dfs(m[s])) {
            cout << "safe\n";
        }
        else {
            cout << "trapped\n";
        }
    }
 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}