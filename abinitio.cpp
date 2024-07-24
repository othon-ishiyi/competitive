#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;



int main() {
    vvi g(4000, vi(4000, 0));
    int v, e, q;
    cin >> v >> e >> q;

    int a, b;
    while(e--) {
        cin >> a >> b;
        g[a][b] = 1;
    }

    int c;

    while(q--) {
        cin >> c;
        switch(c) {
            case 1:
                v++;
                break;
            case 2:
                cin >> a >> b;
                g[a][b] = 1;
                break;
            case 3:
                cin >> a;
                for(int i=0; i<4000; i++) {
                    g[a][i] = 0;
                    g[i][a] = 0;
                }
                break;
            case 4:
                cin >> a >> b;
                    g[a][b] = 0;
            case 5:
                int aux[4000][4000];
                for(int i = 0; i < 4000; i++)
                    for(int j=0; j<4000; j++)
                        aux[i][j] = g[i][j];
                for(int i = 0; i < 4000; i++)
                    for(int j=0; j<4000; j++)
                        g[i][j] = aux[j][i];

                break;
            case 6:
                for(int i = 0; i < 4000; i++)
                    for(int j=0; j<4000; j++)
                        g[i][j] = (g[i][j]? 0 : 1);
                break;
        }
    }

    cout << v << '\n';
    for(int i = 0; i < v; i++) {
        int d = 0, h = 0;
        ll pot = 1;
        for(int j = 0; j < v; j++) {
            if(g[i][j] == 1) {
                h += int(pot)*j;
                d++;
                pot = (pot * 7)%(1000000007);
            }
        }
        cout << d << ' ' << h << '\n';
    }
    
    return 0;
}