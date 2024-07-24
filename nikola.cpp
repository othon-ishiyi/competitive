    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;

    int memo[1000][1001];
    int n;
    int price[1000];

    int dp(int i, int prev) {
        int &ans = memo[i][prev];
        if(i == n-1) {
            return ans = 0;
        }
        if(ans != -1) {
            return ans;
        }
        ans = 1000000000;
        if(i - prev >= 0 and prev != 0) {
            ans = min(ans, dp(i-prev, prev) + price[i-prev]);
        }
        if(i + prev + 1 < n) {
            ans = min(ans, dp(i+prev+1, prev+1) + price[i+prev+1]);
        }
        return ans = min(1000000000, ans);
    }

    void solve() {
        memset(memo, -1, sizeof memo);
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> price[i];
        }
        cout << dp(0, 0) << '\n';
    }

  
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        solve();
        return 0;
    }