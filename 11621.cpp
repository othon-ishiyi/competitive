#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll pow(ll n, int k) {
    if(k == 0) return 1;
    if(k == 1) return n;
    if(k % 2) return pow(n, k-1) * n;
    ll aux = pow(n, k/2);
    return aux*aux;
}

void solve(ll n, vector<ll> &v) {
    cout << *lower_bound(v.begin(), v.end(), n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    vector<ll> v;

    for(int i=0; i<=31; i++) {
        for(int j=0; j<=i; j++) {
            v.push_back(pow(2, j) * pow(3, i-j));
        }
    }

    sort(v.begin(), v.end());

    while(true) {
        cin >> n;
        if(n == 0) break;
        solve(n, v);
    }
    
    return 0;
}