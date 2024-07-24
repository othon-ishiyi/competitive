#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n;
    cin >> n;
    vi lis(n, 0), lds(n, 0), w(n);

    int max_len = 0;

    for(int i=0; i<n; i++) {
        cin >> w[i];
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            if(w[i] > w[j])
                lis[i] = max(lis[i], lis[j]);
            if(w[i] < w[j])
                lds[i] = max(lds[i], lds[j]);
        }

        lis[i] += 1;
        lds[i] += 1;

        max_len = max(max_len, lis[i]+lds[i]-1);
    }

    cout << max_len << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}   