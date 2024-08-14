#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(x) ((x) & -(x))

ll _sieve_size;
vi ndivisors;
vi v;
int n;

int memo[(1 << 14)];
int memo2[(1 << 14)];

int block(int mask) {
    int &ans = memo2[mask];
    if(ans != -1) return ans;
    if(mask == 0) return ans = 0;
    int lsone = LSOne(mask);
    return ans = block(mask-lsone) + v[__builtin_ctz(lsone)];
}

int dp(int mask) {
    int &ans = memo[mask];
    if(ans != -1) return ans;
    if(mask == 0) {
        return ans = 0;
    }

    ans = ndivisors[block(mask)];

    for(int m=1; m<=mask/2; m++) {
        if((mask | m) == mask) {
            ans = max(ans, dp(m) + dp(mask-m));
        }
    }

    return ans;
}

void sieve(ll upperbound) {
    _sieve_size = upperbound+1;
    ndivisors.assign(_sieve_size, 0);
    for(ll i=2; i<_sieve_size; i++) {
        if(ndivisors[i] == 0) {
            for(ll j=i; j<_sieve_size; j+=i) {
                ndivisors[j]++;
            }
        }
    }
}

void solve() {
    memset(memo, -1, sizeof memo);
    memset(memo2, -1, sizeof memo2);
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << dp((1 << n) - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(20000);

    solve();
    return 0;
}