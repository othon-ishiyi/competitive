#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ii> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for(int i=0; i<n; i++) {
        ii p = v[i];
        if(p.first > 0) break;
        ans += 2 * abs(p.first) * ((p.second+k-1)/k); //ceil

        int overflow = (k - p.second % k);
        if(overflow == k) overflow = 0;
        int j=i;
        while(j < n) {
            if(overflow == 0 or v[j].first > 0) {
                break;
            }
            j++;
            if(j < n) if(v[j].first < 0) {
                int delta = min(overflow, v[j].second);
                overflow -= delta;
                v[j].second -= delta;
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        ii p = v[i];
        if(p.first < 0) break;
        ans += 2* abs(p.first) * ((p.second+k-1)/k);

        int overflow = (k - p.second % k);
        if(overflow == k) overflow = 0;
        int j = i;
        while(j >= 0) {
            if(overflow == 0 or v[j].first < 0) {
                break;
            }
            j--;
            if(j >= 0) if(v[j].first > 0) {
                int delta = min(overflow, v[j].second);
                overflow -= delta;
                v[j].second -= delta;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}