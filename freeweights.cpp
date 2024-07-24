#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

bool possible(vi &v, int w) {
    bool between = false;
    int weight;
    for(auto i: v) {
        if(i <= w) continue;
        if(!between) {
            weight = i;
            between = true;
        }
        else {
            if(weight != i) return false;
            between = false;
        }
    }

    return !between;
}

void solve() {
    int N;
    int max_weight = 0;
    cin >> N;
    vi row1(N), row2(N);

    for(int i=0; i<N; i++) {
        cin >> row1[i];
        max_weight = max(max_weight, row1[i]);
    }
    for(int i=0; i<N; i++) {
        cin >> row2[i];
        max_weight = max(max_weight, row2[i]);
    }

    int lo = 0, hi = max_weight;
    while(hi > lo) {
        int m = (hi+lo)/2;
        if(possible(row1, m) and possible(row2, m)) {
            hi = m;
        }
        else {
            lo = m+1;
        }
    }

    cout << hi << '\n';  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}