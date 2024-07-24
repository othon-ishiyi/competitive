#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int n) {
    vector<double> v(1440, -0.08);

    for(int i=0; i<n; i++) {
        int t;
        double val; 
        cin >> t >> val;
        v[t] += val;
    }

    double ans = 0;
    double sum = 0;
    double topen = 0, tclose, taux = 0;

    for(int t=0; t<1440; t++) {
        sum += v[t];
        if(ans < sum) {
            topen = taux;
            tclose = t;
            ans = sum;
        }
        if(sum < 0) {
            sum = 0;
            taux = t+1;
        }
    }

    if(ans > 0)
        cout << ans << ' ' << topen << ' '<< tclose << '\n';
    else
        cout << "no profit\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;
        solve(n);
    }
        
    return 0;
}