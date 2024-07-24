#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

struct cmp {
    bool operator()(ii a, ii b) {
        if(a.second != b.second) {
            return a.second < b.second;
        }
        else
            return a.first < b.first;
    }
};


void solve() {
    int n;
    cin >> n;

    vector<ii> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp());

    priority_queue<int> pq;

    int time = 0;
    for(auto p: v) {
        pq.push(p.first);
        time += p.first;
        if(time > p.second) {
            time -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << "\n\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
    return 0;
}