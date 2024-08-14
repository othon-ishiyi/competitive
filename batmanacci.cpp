#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vll fibo = {0,1};
ll n, k;

char find(ll n, ll k) {
    if(n == 1) return 'N';
    if(n == 2) return 'A';
    if(k <= fibo[n-2]) {
        return find(n-2, k);
    }
    return find(n-1, k - fibo[n-2]);
}

void solve() {

    for(ll i=2; i<n; i++) {
        fibo.push_back(fibo[i-1] + fibo[i-2]);
        if(fibo[i] >= 1e18) {
            fibo[i] = (1e18) + 1;
        }
    }

    cout << find(n, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> k)
        solve();
    return 0;
}