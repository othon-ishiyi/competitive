#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int N;
vi w;
ll total = 0;

ll pow(ll n, int k) {
    if(k == 0) return 1;
    if(k == 1) return n;
    if(k % 2) return pow(n, k-1) * n;
    ll aux = pow(n, k/2);
    return aux*aux;
}

bool rb(int col, int weight) {
    if(weight >= 200) {
        ll pot = pow(ll(2), N-col);
        total += pot*ll(weight);
        for(int i=col; i<N; i++) {
            total += ll(w[i]) * pot/ll(2);
        }
        return true;
    }
    if(col == N) {
        return false;
    }
    bool ok = rb(col+1, weight + w[col]);
    if(ok) {
        rb(col+1, weight);
        return true;
    }
    return false;
}

void solve() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        w.push_back(a);
    }

    rb(0, 0);
    cout << total << '\n';
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}