#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, m;
vi lab(100001);
vi g[100001];

int kahn1(vi cnt) {
    queue<int> q1, q2;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(cnt[i] == 0) {
            lab[i] == 1 ? q1.push(i): q2.push(i);
        }
    }

    int v;
        
    while(!q1.empty() or !q2.empty()) {
        ans++;
        while(!q1.empty()) {
            v = q1.front();
            q1.pop();
            for(int next: g[v]) {
                cnt[next]--;
                if(cnt[next] == 0) {
                    lab[next] == 1 ? q1.push(next): q2.push(next);
                }
            }
        }
        if(q2.empty()) break;
        ans++;
        while(!q2.empty()) {
            v = q2.front();
            q2.pop();
            for(int next: g[v]) {
                cnt[next]--;
                if(cnt[next] == 0) {
                    lab[next] == 1 ? q1.push(next): q2.push(next);
                }
            }
        }
    }

    return max(0, ans - 1);
}

int kahn2(vi cnt) {
    queue<int> q1, q2;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(cnt[i] == 0) {
            lab[i] == 1 ? q1.push(i): q2.push(i);
        }
    }

    int v;
    
    while(!q1.empty() or !q2.empty()) {
        ans++;
        while(!q2.empty()) {
            v = q2.front();
            q2.pop();
            for(int next: g[v]) {
                cnt[next]--;
                if(cnt[next] == 0) {
                    lab[next] == 1 ? q1.push(next): q2.push(next);
                }
            }
        }
        if(q1.empty()) break;
        ans++;
        while(!q1.empty()) {
            v = q1.front();
            q1.pop();
            for(int next: g[v]) {
                cnt[next]--;
                if(cnt[next] == 0) {
                    lab[next] == 1 ? q1.push(next): q2.push(next);
                }
            }
        }
    }

    return ans - 1;
}

void solve() {
    cin >> n >> m;

    vi cnt(n+1, 0);
    for(auto &v: g) {
        v.clear();
    }

    for(int i=1; i<=n; i++) {
        cin >> lab[i];
    }

    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        cnt[b]++;
    }

    cout << min(kahn1(cnt), kahn2(cnt)) << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}