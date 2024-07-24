#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

class veggie {
public:
    double w, ncuts;
    veggie(double w, int ncuts) {
        this->w = w;
        this->ncuts = ncuts;
    }
    double piece() {
        return w/(ncuts+1);
    }
};

struct cmp {
    bool operator()(veggie a, veggie b) {
        return a.piece() < b.piece();
    }
};

void solve() {
    double ratio; int n;
    cin >> ratio >> n;
    ratio -= 0.0001;

    priority_queue<veggie, vector<veggie>, cmp> pq;

    double tiny = 1000000;

    for(int i=0; i<n; i++) {
        double w;
        cin >> w;
        pq.push(veggie(w, 0));
        tiny = min(tiny, w);
    }


    while(true) {
        veggie t = pq.top();
        if(tiny/t.piece() > ratio) break;
        int w = t.w;
        int ncuts = t.ncuts + 1;
        pq.pop();
        t = veggie(w, ncuts);
        pq.push(t);
        if(t.piece() < tiny) {
            tiny = t.piece();
        }
    }

    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top().ncuts;
        pq.pop();
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}