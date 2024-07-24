#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int l, int g) {
    
    vector<ii> v(g);

    for(int i=0; i<g; i++) {
        int x, r;
        cin >> x >> r;
        v[i].first = x-r;
        v[i].second = x+r;
    }
    sort(v.begin(), v.end());

    int minStation = 0;
    int reach = 0, max_range = -1;
    for(int i=0; i<g and max_range < l; i++) {
        if(v[i].first > reach) {
            if(max_range < v[i].first) {
                cout << -1 << '\n';
                return;
            }
            reach = max_range;
            minStation++;
        }
        max_range = max(max_range, v[i].second);
    }

    if(max_range >= l) {
        minStation++;
    }
    else {
        cout << -1 << '\n';
        return; 
    }

    cout << g - minStation << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, g;

    while(true) {
        cin >> l >> g;
        if(l == 0) break;
        solve(l, g);
    }
    return 0;
}