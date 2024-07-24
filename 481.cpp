#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int a;
    vector<int> v;
    while(cin >> a) {
        v.push_back(a);
    }

    vi L, p, L_id;
    for(int i=0; i<v.size(); i++) {
        auto lb = lower_bound(L.begin(), L.end(), v[i]);
        int pos = lb - L.begin();
        if(pos == L.size()) {
            L.push_back(v[i]);
            L_id.push_back(i);
        }
        else {
            L[pos] = v[i];
            L_id[pos] = i;
        }

        if(pos != 0) {
            p.push_back(L_id[pos-1]);
        }
        else {
            p.push_back(-1);
        }
    }

    cout << L.size() << '\n';

    vi ans(L.size());
    int it = L_id[L.size()-1];
    for(int i=L.size()-1; i>=0; i--) {
        ans[i] = v[it];
        it = p[it];
    }
    cout << "-\n";
    for(auto i: ans) {
        cout << i << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}