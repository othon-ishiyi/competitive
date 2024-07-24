#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n;
    cin >> n;
    vi h(n), w(n), lis(n, 0), lds(n, 0);
    int max_lis = 0, max_lds = 0;

    for(int i=0; i<n; i++) {
        cin >> h[i];
    }
    for(int i=0; i<n; i++) {
        cin >> w[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(h[i] > h[j]) {
                lis[i] = max(lis[i], lis[j]);
            }
            if(h[i] < h[j]) {
                lds[i] = max(lds[i], lds[j]);
            }
        }
        lis[i] += w[i];
        lds[i] += w[i];
        max_lis = max(max_lis, lis[i]);
        max_lds = max(max_lds, lds[i]);
    }

    if(max_lis >= max_lds) {
        cout << "Increasing (" << max_lis << "). ";
        cout << "Decreasing (" << max_lds << ").\n";
    }
    else {
        cout << "Decreasing (" << max_lds << "). ";
        cout << "Increasing (" << max_lis << ").\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cout << "Case " << i << ". ";
        solve();
    } 
    return 0;
}