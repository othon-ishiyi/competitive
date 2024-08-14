#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n;
vector<string> ans;
int visited[101];
int cnt[101];

vi g[101];

void kahn() {
    priority_queue<int, vi, greater<int>> q;
    for(int i=0; i<n; i++) {
        if(cnt[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int v = q.top();
        q.pop();
        for(int &next: g[v]) {
            cnt[next]--;
            if(cnt[next] == 0) {
                q.push(next);
            }
        }
        cout << ' ' << ans[v];
    }
}


void solve() {
    for(auto &v: g) {
        v.clear();
    }
    memset(visited, 0, sizeof visited);
    memset(cnt, 0, sizeof cnt);
    ans.clear();
    unordered_map<string, int> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        ans.push_back(s);
        m[s] = i;
    }

    int u;
    cin >> u;
    while(u--) {
        string a, b;
        cin >> a >> b;
        g[m[a]].push_back(m[b]);
        cnt[m[b]]++;
    }
    kahn();
    cout << ".\n\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ncase = 1;

    while(cin >> n) {
        cout << "Case #" << ncase++ << ": Dilbert should drink beverages in this order:";
        solve();
    }
    return 0;
}