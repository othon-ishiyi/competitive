#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int memo[31][10010][31];
ll comb[31][31];
int n, t, k;

#define LSOne(x) ((x) & -(x))


ll dp_comb(int n, int k) {
    ll &ans = comb[n][k];
    if(ans != -1) {
        return ans;
    }
    if(k == 0) {
        return ans = 1;
    }
    return ans = dp_comb(n, k-1)*ll(n-k+1)/ll(k);
}


void solve() {
    cin >> n;
    vi val1, val2;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(i < n/2)
            val1.push_back(a);
        else
            val2.push_back(a);
    }

    cin >> k >> t;
    
    vi sum1[31], sum2[31];
    for(int i=0; i<(1<<(n/2)); i++) {
        int u = __builtin_popcount(i);
        int s = 0;
        for(int j=i; j; j -= LSOne(j)) {
            int z = __builtin_ctz(LSOne(j));
            s += val1[z];
        }
        sum1[u].push_back(s);
    }
    for(int i=0; i<(1<<(n-(n/2))); i++) {
        int u = __builtin_popcount(i);
        int s = 0;
        for(int j=i; j; j -= LSOne(j)) {
            int z = __builtin_ctz(LSOne(j));
            s += val2[z];
        }
        sum2[u].push_back(s);
    }

    for(int i=0; i<n/2; i++) {
        sort(sum1[i].begin(), sum1[i].end());
    }
    for(int i=0; i< n - n/2; i++) {
        sort(sum2[i].begin(), sum2[i].end());
    }

    int sol = 0;
    for(int i=0; i<min(k, n/2); i++) {
        for(int p: sum1[i]) {
            auto lb = lower_bound(sum2[max(0, k-i-1)])
        }
    }



    ll total = dp_comb(n, k);
    cout << sol << " : " << total - sol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=0; i<31; i++) {
        for(int j=0; j<31; j++) {
            comb[i][j] = -1;
        }
    }
    for(int i=1; i<=N; i++) {
        cout << "Game " << i << " -- ";
        solve();
    }
        
    return 0;
}