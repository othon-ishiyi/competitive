#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int a, d;
vector<int> asc_time, desc_time;

double get_diff(double time, unordered_map<int, double>& ma, unordered_map<int, double> &md) {
    auto pa = upper_bound(asc_time.begin(), asc_time.end(), int(time));
    auto pb = upper_bound(desc_time.begin(), desc_time.end(), int(time));
    int ta_2 = *pa;
    int td_2 = *pb;
    int ta_1 = *(--pa);
    int td_1 = *(--pb);

    double ha = ma[ta_1] + (time - double(ta_1))/(double(ta_2) - double(ta_1)) * (ma[ta_2] - ma[ta_1]);
    double hd = md[td_1] + (time - double(td_1))/(double(td_2) - double(td_1)) * (md[td_2] - md[td_1]);

    return ha - hd;
}

void solve() {
    cin >> a >> d;
    unordered_map<int, double> ma, md;
    asc_time.assign(a+2, 0);
    desc_time.assign(d+2, 0);
    asc_time[a+1] = 1000;
    desc_time[d+1] = 1000;
    ma[0] = double(0);
    md[1000000] = double(0);

    double total_height = 0;
    for(int i=1; i<=a; i++) {
        double h; int t;
        cin >> h >> t;
        asc_time[i] = asc_time[i-1] + t;
        total_height += h;
        ma[asc_time[i]] = h + ma[asc_time[i-1]];
    }
    md[0] = total_height;
    ma[1000000] = total_height;
    for(int i=1; i<=d; i++) {
        double h; int t;
        cin >> h >> t;
        desc_time[i] = desc_time[i-1] + t;
        md[desc_time[i]] = md[desc_time[i-1]] - h;
    }

    double lo = 0.0, hi = 500000.0;

    for(int it=0; it<5000; it++) {
        double m = (lo+hi)/double(2.0);
        if(get_diff(m, ma, md) < 0) {
            lo = m;
        }
        else {
            hi = m;
        }
    }

    cout << setprecision(6) << hi << '\n';

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}