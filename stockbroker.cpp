#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<bool> sell(n, true);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    ll buy_value = v[n-1];

    for(int i=n-2; i>=0; i--) {
        if(v[i] > buy_value) {
            buy_value = v[i];
        }
        else {
            buy_value = min(buy_value, v[i]);
            v[i] = buy_value;
            sell[i] = false;
        }
    }

    ll cash = 100, stock = 0;;
    for(int i=0; i<n; i++) {
        if(sell[i]) {
            cash += v[i]*stock;
            stock = 0;
        }
        else {
            stock += cash/v[i];
            cash %= v[i];
        }
        if(stock > 100000) {
            cash += v[i]*(stock-100000);
            stock = 100000;
        }
    }

    cout << cash << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}