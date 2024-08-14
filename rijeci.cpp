#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vll fibo = {0,1};

void solve() {
    ll n;
    cin >> n;

    for(ll i=2; i<=n; i++) {
        fibo.push_back(fibo[i-1] + fibo[i-2]);
    }

    cout << fibo[n-1] << ' ' << fibo[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}