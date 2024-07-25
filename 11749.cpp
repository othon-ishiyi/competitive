    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef long double ld;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;

    double eps = 0.00001;

    vi g[510];
    int visited[510];

    int n, m;
    int cnt = 0;

    void dfs(int v) {
        pair<int, ll> ans = {1, 0};
        visited[v] = 1;
        for(int i: g[v]) {
            if(!visited[i]){
                dfs(i);
            }
        }
        cnt++;
    }

    void solve() {
        memset(visited, 0, sizeof visited);
        for(int i=0; i<510; i++) {
            g[i].clear();
        }

        vvi aux(m, vi(3));
        int max_w = INT_MIN;

        for(int i=0; i<m; i++) {
            cin >> aux[i][0] >> aux[i][1] >> aux[i][2];
            max_w = max(max_w, aux[i][2]);
        }

        for(int i=0; i<m; i++) {
            if(aux[i][2] == max_w) {
                int a = aux[i][0];
                int b = aux[i][1];
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }

        int ans = 0;

        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                cnt = 0;
                dfs(i);
                ans = max(ans, cnt);
            }
        }

        cout << ans << '\n';
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        while(true) {
            cin >> n >> m;
            if(n == 0) return 0;
            solve();
        }
        
        return 0;
    }