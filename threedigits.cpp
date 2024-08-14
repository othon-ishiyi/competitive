#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n;
ll mod;
vll pot10;

void solve() {
    ll f = 1;
    for(ll i=1; i<=n; i++) {
        mod = pot10[(int)floor(1 + log10((double)i))-1];
        f *= i;
        while(f % 10 == 0) f/=10;
        f = f % mod;
    }

    if(n <= 6)
        cout << f % 1000 << '\n';
    else {
        printf("%03d\n", int(f % 1000));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll M = 1e17;
    for(int i=0; i<10; i++) {
        pot10.push_back(M);
        M /= 10;
    }

    while(cin >> n)
        solve();

    return 0;
}