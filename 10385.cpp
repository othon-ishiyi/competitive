#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int t;
int N;
vector<double> run, cyc;

double margin(double r) {
    double k = double(t) - r;
    double cheat_time = r/run[N-1] + k/cyc[N-1];
    double min_diff = 100000000;

    for(int i=0; i<N-1; i++) {
        double time = r/run[i] + k/cyc[i];
        min_diff = min(time-cheat_time, min_diff);
    }

    return min_diff;
}

void solve() {
    cin >> N;
    run.assign(N, 0.0);
    cyc.assign(N, 0.0);


    for(int i=0; i<N; i++) {
        cin >> run[i] >> cyc[i];
    }

    double lo = 0, hi = t;
    int rep = 100;
    double diff;
    while(rep--) {
        double r1 = (2*lo+hi)/3, r2 = (lo+2*hi)/3;
        diff = margin(r1);
        if(diff >= margin(r2)) {
            hi = r2;
        }
        else {
            lo = r1;
        }
    }

    int diff_seconds = round(diff*3600);
    if(diff_seconds >= 0) {
        cout << "The cheater can win by " << diff_seconds << " seconds with r = " << fixed << setprecision(2) << (hi*100)/100.0; 
        cout << "km and k = " << fixed << setprecision(2) << double(t)-round(hi*100)/100.0 << "km.\n";
    }
    else {
        cout << "The cheater cannot win.\n";
    }


}

int main() {
    while(cin >> t)
        solve();
    return 0;
}