#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;

int calc(vi A, vi B){
    int a = 0, b = 100;
    bool end = false;
    int ans = 0;

    while(true){
        while(A[a] == 0){
            a++;
            if(a > 100){
                end = true;
                break;
            }
        }
        while(B[b] == 0){
            b--;
            if(b < 0){
                end = true;
                break;
            }
    
        }
        if(end)
            return ans;
        ans = max(ans, a+b);
        int m = min(A[a], B[b]);
        A[a] -= m;
        B[b] -= m;
    }
    return ans;
}

void solve() {
    vi A(101, 0), B(101,0);
    int N;
    cin >> N;

    for(int k = 1; k<=N; k++){
        int a, b;
        cin >> a >> b;
        A[a]++;
        B[b]++;
        cout << calc(A, B) << '\n';
    }


}

int main() {
    solve();
    return 0;
}