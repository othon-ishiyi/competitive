#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<vector<ii>> memo(101, vector<ii>(10010));
vi value(101);
int n;

ii dp(int i, int val) {
    if(val <= 0){
        return {-val, 0};
    }
    if(i == n) {
        return {INT_MAX, 0};
    }
    ii &ans = memo[i][val];
    if(ans != make_pair(-1,-1)) return ans;
    ii aux = dp(i+1, val-value[i]);
    aux.second++;

    return ans = min(dp(i+1, val), aux);
}

void solve() {
    int target;
    cin >> target >> n;
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }
    for(int i=0; i<101; i++) {
        for(int j=0; j<10010; j++) {
            memo[i][j] = {-1,-1};
        }
    }
    ii p = dp(0, target);

    cout << target + p.first << ' ' << p.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}