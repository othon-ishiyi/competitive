#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

bool verify(vi &sums, vi &ans, int n) {
    multiset<int> s;
    for(auto i: sums) {
        s.insert(i);
    }

    s.erase(s.find(sums[0]));

    for(int cur = 2; cur < n;) {
        for(int i=0; i<cur; i++) {
            if(!s.count(ans[i]+ans[cur])) {
                return false;
            }
            s.erase(s.find(ans[i] + ans[cur]));
        }

        if(cur == n-1) return true;

        ans[++cur] = *s.begin() - ans[0];
    }

    return true;   
}

void solve(int n) {
    vi sums(n*(n-1)/2);
    for(int i=0; i<n*(n-1)/2; i++) {
        cin >> sums[i];
    }
    sort(sums.begin(), sums.end());

    vi ans(n);
    for(int u=2; u<n; u++) {
        if((sums[0] + sums[1] - sums[u]) % 2) continue;
        ans[0] = (sums[0] + sums[1] - sums[u])/2;
        ans[1] = sums[0] - ans[0];
        ans[2] = sums[1] - ans[0];

        if(verify(sums, ans, n)) {
            int i;
            for(i=0; i<n-1; i++) {
                cout << ans[i] << ' ';
            }
            cout << ans[i] << '\n';
            return;
        }
    }
    cout << "Impossible\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(cin >> n) {
        solve(n);
    }

    return 0;
}