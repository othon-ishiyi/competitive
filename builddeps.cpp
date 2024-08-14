// Simpler solution at builddeps2.cpp

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[100010];
int visited[100010];
bool dep[100010];
int n;
int root;
vector<string> ans;

void topsort(int i) {
    visited[i] = 1;

    for(int v: g[i]) {
        if(!visited[v]) {
            topsort(v);
        }
        dep[i] += dep[v];
    }

    if(dep[i]) cout << ans[i] << '\n';
}

void solve() {
    unordered_map<string, int> m;

    memset(visited, 0, sizeof visited);
    memset(dep, false, sizeof dep);

    cin >> n;
    int idx = 0;

    cin.ignore();

    for(int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string a;
        ss >> a;
        a.pop_back();

        if(!m.count(a)) {
            m.insert({a, idx++});
            ans.push_back(a);
        }
        int v = m[a];

        while(ss >> a) {
            if(!m.count(a)) {
                m.insert({a, idx++});
                ans.push_back(a);
            }
            g[v].push_back(m[a]);
        }
    }

    string s;
    cin >> s;
    root = m[s];
    dep[root] = 1;
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) topsort(i);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}