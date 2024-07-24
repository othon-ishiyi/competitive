#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int memo[110][30001];
int price[101];
int n;

int knapsack(int order, int money) {
    int &ans = memo[order][money];
    if(ans != -1) {
        return ans;
    }
    ans = 0;
    if(order == n) {
        return ans = (money == 0);
    }
    for(int k=0; k <= money/price[order]; k++) {
        ans += knapsack(order+1, money-k*price[order]);
        ans = min(2, ans);
        if(ans == 2) break;
    }

    return ans;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> price[i];
    }
    int m;
    cin >> m;
    while(m--) {
        int money;
        cin >> money;
        int ans = knapsack(0, money);
        if(ans == 1) {
            for(int i=0; i<n; i++) {
                for(int j=1; j<=money/price[i]; j++) {
                    if(memo[i+1][money-j*price[i]] == 1) {
                        money -= j*price[i];
                        while(j--) {
                            cout << i+1 << ' ';
                        }
                        break;
                    }
                }
            }
            cout << '\n';
        }
        else if(ans > 1) {
            cout << "Ambiguous\n";
        }
        else {
            cout << "Impossible\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}