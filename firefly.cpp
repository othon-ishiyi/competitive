#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, h;
    cin >> n >> h;
    vi hits(h+1, 0);
    hits[0] = n/2;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if(i % 2) {
            hits[a+1]--;
        }
        else {
            hits[h+1-a]++;
        }
    }
    int min_hits = n/2;
    int cnt = 0;
    for(int i=1; i<=h; i++) {
        hits[i] += hits[i-1];
        if(min_hits > hits[i]) {
            min_hits = hits[i];
            cnt = 1;
        }
        else if(min_hits == hits[i]) {
            cnt++;
        }
            
    }

    cout << min_hits << ' ' << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}