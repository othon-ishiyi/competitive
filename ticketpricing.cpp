    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;

    int memo[53][301];
    vector<ii> v[53];
    int n, w;

    int dp(int week, int seats) {
        if(week > w) {
            return 0;
        }
        int &ans = memo[week][seats];

        if(ans != -1) {
            return ans;
        }

        if(seats == 0) {
            return ans = 0;
        }

        ans = 0;

        for(ii p: v[week]) {
            int price = p.first;
            int sell = min(seats, p.second);
            ans = max(ans, dp(week+1, seats-sell) + price*sell);
        }

        return ans;
    }

    void solve() {
        memset(memo, -1, sizeof memo);
        cin >> n >> w;
        for(int i=0; i<=w; i++) {
            int k;
            cin >> k;
            v[i].assign(k, {0,0});
            for(int j=0; j<k; j++) {
                cin >> v[i][j].first;
            }
            for(int j=0; j<k; j++) {
                cin >> v[i][j].second;
            }
        }

        cout << dp(0, n) << '\n';
        for(ii p: v[0]) {
            int price = p.first;
            int sell = min(n, p.second);
            if(price*sell + dp(1, n-sell) == dp(0, n)) {
                cout << price << '\n';
                return;
            }
        }
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        solve();
        return 0;
    }