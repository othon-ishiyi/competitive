    #include <bits/stdc++.h>
    #define ll long long
    #define vi vector<int>
    #define vvi vector<vector<int>>
    #define vii vector<pair<int,int>>

    using namespace std;

    void solve(vector<queue<ll>> &q) {
        vector<ll> v;
        int N;
        cin >> N;
        ll A, B, C, X, Y;

        cin >> A >> B >> C;
        cin >> X >> Y;
        ll S = A;
        v.push_back(S);

        while(--N) {
            S = (S*B + A)%C;
            v.push_back(S);
        }

        int D=1;
        int digits = 2;
        int base = 1e5;


        while(digits--){
            for(ll n: v){
            q[(n/D)%base].push(n);
            }
            D *= base;
            int k = 0;
            for(int i=0; i<base;i++){
                while(!q[i].empty()){
                    v[k++] = q[i].front();
                    q[i].pop(); 
                }          
            }
        }

        ll V=0;
        for(auto u: v){
            V = (V*X+u)%Y;
        }

        cout << V << '\n'; 
    }

    int main() {
        int N;
        cin >> N;
        int base = 1e5;
        vector<queue<ll>> q(base);
        while(N--)
            solve(q);
        return 0;
    }