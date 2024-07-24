#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int memo[201][1000][25];
int favour[100];
int price[100];
int n, x, t, k;

int total_price(int price) {
    float total = 1.1*float((n+1)*t + price);
    return ceil(total);
}

int max_favour(int item, int spent_money, int n_dumps) {
    int &ans = memo[item][spent_money][n_dumps];
    if(ans != -1) return ans;

    if(n_dumps == 2*(n+1)) return ans = 0;

    if(item == 2*k) {
        return ans = 0;
    }

    int i=item/2;
    if(total_price(price[i] + spent_money) > (n+1)*x) {
        return ans = max_favour(item+1, spent_money, n_dumps);
    }
    else {
        return ans = max(max_favour(item+1, spent_money, n_dumps),
        max_favour(item+1, spent_money + price[i], n_dumps+1) + favour[i]);
    }

}

void solve() {
    memset(memo, -1, sizeof memo);

    for(int i=0; i<k; i++){
        cin >> price[i];
        int sum_favour = 0;
        for(int j=0; j<n+1; j++) {
            int f;
            cin >> f;
            sum_favour += f;
        }
        favour[i] = sum_favour;

    }

    int ans = max_favour(0, 0, 0);

    cout << fixed << setprecision(2) << round(double(100*ans)/(n+1))/100 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        cin >> n >> x >> t >> k;
        if(n == 0) return 0;
        solve();
    }

    return 0;
}