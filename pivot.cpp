#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve() {
    int N, ans = 0;
    vi v;

    set<int> sorted;

    cin >> N;
    while(N--){
        int u;
        cin >> u;
        v.push_back(u);
        sorted.insert(u);
    }

    int a = -1 , b = *(sorted.begin());

    for(int i = 0; i < v.size(); i++){
        int pivot = v[i];
        sorted.erase(v[i]);
        if(i > 0) if(v[i-1] > a) a = v[i-1];
        if(v[i] == b) b = (sorted.empty()? INT_MAX:*(sorted.begin()));

        if(v[i] > a and v[i] < b){
            //cout << v[i] << " ";
            ans++;
        }
    }
    //cout << "\n";
    cout << ans;
}

int main() {
    solve();
    return 0;
}