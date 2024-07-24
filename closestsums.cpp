#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int n) {
    vi v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    vi s;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            s.push_back(v[i]+v[j]);
        }
    }

    sort(s.begin(), s.end());

    int m;
    cin >> m;

    while(m--) {
        int q, value;
        cin >> q;
        auto l = lower_bound(s.rbegin(), s.rend(), q, std::greater<int>());
        auto u = lower_bound(s.begin(), s.end(), q);


        if(l == s.rend()) {
            value = *u;
        }
        else if(u == s.end()) {
            value = *l;
        }
        else {
            value = ((*u - q > q - *l)? *l : *u);
        }

        cout << "Closest sum to " << q << " is " << value << ".\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i=1;

    while(cin >> n) {
        cout << "Case " << i++ << ":\n";
        solve(n);
    }

    return 0;
}