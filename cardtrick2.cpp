#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;


void solve() {
    int n;
    cin >> n;

    deque<int> dq;
    for(int i=0; i<n; i++) {
        dq.push_back(i);
    }

    map<int, int> m;

    for(int i=1; i<=n; i++) {
        int j=i;
        int card;
        while(j--) {
            card = dq.front();
            dq.pop_front();
            dq.push_back(card);
        }
        card = dq.front();
        dq.pop_front();
        m[card] = i;
    }

    for(auto i: m) {
        cout << i.second << ' ';
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    cin >> i;

    while(i--) {
        solve();
    }
    return 0;
}