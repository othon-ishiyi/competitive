#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {  
    int r, c;
    cin >> r >> c;
    vector<vector<char>> lot(r, vector<char>(c));

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> lot[i][j];
        }
    }

    vvi possible(r-1, vi(c-1,1)), cars(r-1, vi(c-1));

    for(int i=0; i<r-1; i++) {
        for(int j=0; j<c-1; j++) {
            if(lot[i][j] == '#'|| lot[i+1][j] == '#'|| lot[i][j+1] == '#'|| lot[i+1][j+1] == '#') {
                possible[i][j] = 0;
            }
            for(int u=0; u<=1; u++) {
                for(int v=0; v<=1; v++) {
                    if(lot[i+u][j+v] == 'X') cars[i][j]++;
                }
            }
        } 
    }

    vi ans(5, 0);

    for(int i=0; i<r-1; i++) {
        for(int j=0; j<c-1; j++) {
            if(possible[i][j]) ans[cars[i][j]]++;
        }
    }

    for(int i=0; i<5; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    solve();

    return 0;
}