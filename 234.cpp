#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int N) {
    vi len(N), ans(N);
    for(int i=0; i<N; i++) {
        cin >> len[i];
    }

    sort(len.begin(), len.end());

    int M;
    cin >> M;
    vector<ii> points(M);
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }

    vi cur_miss(6, INT_MAX);

    do {
        vi miss(M, INT_MAX);
        vi miss_priority(6, 0);
        int time = 0;
        for(int i=0; i<N; i++) {
            time += len[i];
            for(int j=0; j<M; j++) {
                miss[j] = min(abs(time-points[j].second), miss[j]);
            }
        }

        for(int j=0; j<M; j++) {
            miss_priority[points[j].first] += miss[j];
        }

        bool cmp = true;
        for(int j=1; j<=5; j++) {
            if(cur_miss[j] < miss_priority[j]) {
                cmp = false;
                break;
            }
            if(cur_miss[j] > miss_priority[j]) {
                break;
            }
        }
        if(cmp) {
            cur_miss = miss_priority;
            ans = len;
        }
    } while(next_permutation(len.begin(), len.end()));

    int sum_miss = 0;
    for(int i=1; i<5; i++) {
        if(cur_miss[i] != INT_MAX) {
            sum_miss += cur_miss[i];
        }
    }

    cout << "\tOrder:";
    for(int i: ans) {
        cout << ' ' << i;
    }
    cout << "\n\tError: " << sum_miss << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, i=1;

    while(true) {
        cin >> N;
        if(N == 0) break;
        cout << "Data set " << i++ << '\n';
        solve(N);
    }
    return 0;
}