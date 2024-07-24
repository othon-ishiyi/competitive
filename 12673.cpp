#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int n, int g) {
    vi diff(n);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        diff[i] = b-a;
    }

    sort(diff.begin(), diff.end());

    int delta = 0;
    int i;

    for(i=0; i<n; i++) {
        if(diff[i] < 0) {
            delta += 3;
        }
        else if(g > diff[i]) {
            g -= diff[i]+1;
            delta += 3;
        }
        else if(g == diff[i]) {
            g -= diff[i];
            delta += 1;
        }
        else {
            while(diff[min(n-1, i)] == 0 and i < n) {
                i++;
                delta++;
            }
            break;
        }
    }


    cout << delta << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, g;

    while(cin >> n >> g) {
        solve(n, g);
    }
    return 0;
}