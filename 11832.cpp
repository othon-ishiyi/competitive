#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int n, f;
int adj = 40000;

int t[41];
int memo[41][80010];

int knapsack(int i, int cash) {
    int &ans = memo[i][cash+adj];
    if(ans != INT_MAX) {
        return ans;
    }
    if(i == n) {
        return ans = (cash == f);
    }
    ans = (-1)*(knapsack(i+1, cash-t[i]) != 0) + 2*(knapsack(i+1, cash+t[i]) != 0);
    return ans;
}

void solve() {
    for(int i=0; i<41; i++) {
        for(int j=0; j<80010; j++) {
            memo[i][j] = INT_MAX;
        }
    }
    for(int i=0; i<n; i++) {
        cin >> t[i];
    }
    int ans = knapsack(0, 0);
    if(ans == 0) {
        cout << "*\n";
        return;
    }

    for(int i=0; i<n; i++) {
        bool a=false, b=false;
        for(int cash=0; cash<80000; cash++) {
            if(memo[i][cash] == 1) {
                a = true;
                b = true;
            }
            if(memo[i][cash] == 2) {
                b = true;
            }
            if(memo[i][cash] == -1) {
                a = true;
            }
        }
        if(a and b) {
            cout << '?';
        }
        else if(a) {
            cout << '-';
        }
        else if(b){
            cout << '+';
        }
        else {
            cout << 'e';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        cin >> n >> f;
        if(n == 0) return 0;
        solve();
    }
    
    return 0;
}