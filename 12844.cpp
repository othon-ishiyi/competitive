#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    vector<int> v;
    vi w(5), freq(401, 0);
    int total = 0;
    for(int i=0; i<10; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        freq[a]++;
    }

    vi freq_(401, 0);

    for(w[0]=0; w[0]<=v[0]/2; w[0]++) {
        w[1] = v[0] - w[0];
        w[2] = v[1] - w[0];
        w[4] = v[8] - w[2];
        w[3] = v[9] - w[4];

        bool ok = true;

        for(int i=0; i<5; i++) {
            for(int j=i+1; j<5; j++) {
                freq_[w[i]+w[j]]++;
            }
        }

        for(int i=0; i<10;i++) {
            if(freq_[v[i]] != freq[v[i]]) ok = false;
        }

        if(ok) break;

        for(int i=0; i<5; i++) {
            for(int j=i+1; j<5; j++) {
                freq_[w[i]+w[j]]--;
            }
        }
    }

    for(int i=0; i<5; i++) {
        cout << ' ' << w[i];
    }
    cout << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<= n; i++) {
        cout << "Case " << i << ':';
        solve();
    }

    return 0;
}