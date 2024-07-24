#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void printNum(int a) {
    if(a<=20){
        cout << "single " << a << '\n';
        return;
    }
    if(a%3==0){
        cout << "triple " << a/3 << '\n';
        return;
    }
    cout << "double " << a/2 << '\n';
    return;
}

void solve() {
    vi points;
    for(int i=1; i<=20; i++) {
        points.push_back(i);
        points.push_back(2*i);
        points.push_back(3*i);
    }

    sort(points.begin(), points.end());

    int n;
    cin >> n;

    int a, b, c;
    for(a=0; a<points.size(); a++) {
        if(points[a] == n) {
            printNum(points[a]);
            return;
        }
        if(2*points[a] > n) {
            cout << "impossible\n";
            return;
        }
        for(b=a; b<points.size(); b++) {
            if(points[a] + points[b] == n) {
                printNum(points[a]);
                printNum(points[b]);
                return;
            }
            if(points[a]+2*points[b]>n) {
                continue;
            }

            for(c=b; c<points.size(); c++) {
                if(points[a]+points[b]+points[c] == n) {
                    printNum(points[a]);
                    printNum(points[b]);
                    printNum(points[c]);
                    return;
                }
                if(points[a]+points[b]+points[c] > n) {
                    break;
                }
            }
        }
    }
    cout << "impossible\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}