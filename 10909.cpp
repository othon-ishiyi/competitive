#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#include <ext/pb_ds/assoc_container.hpp> // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

void solve() {
    int MAX = 2000000;
    bool lucky[MAX+1] = {false};
    indexed_set s;

    for(int i=1; i<=MAX; i+=2){
        s.insert(i);
    }

    for(int i=1; i<s.size(); i++){
        int step = *s.find_by_order(i);
        if(step >= s.size()){
            break;
        }
        for(int j = step-1; j < s.size(); j+=step-1){
            s.erase(s.find_by_order(j));
        }
    }

    for(auto it = s.begin(); it != s.end(); it++) {
        lucky[*it] = true;
    }

    int n;

    while(scanf("%d", &n) != EOF){
        if(n & 1 == 1){
            cout << n << " is not the sum of two luckies!\n";
            continue;
        }
        int i;
        for(i = n/2; i > 0; i--) {
            if(lucky[i] and lucky[n-i]){
                break;
            }
        }

        if(i){
            cout << n << " is the sum of " << i << " and " << n - i << ".\n";
            continue;
        }

        cout << n << " is not the sum of two luckies!\n";
        
    }





    

}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    solve();
    return 0;
}