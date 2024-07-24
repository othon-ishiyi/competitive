#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve() {
    deque<int> q1, q2;
    char cmd[100];

    int n, a;

    scanf("%d", &n);
    while(n--){
        scanf("%s %d", cmd, &a);
        if(!strcmp(cmd, "get")){
            if(a >= q1.size())
                printf("%d\n", q2[a-q1.size()]);
            else
                printf("%d\n", q1[a]);
            continue;
        }
        if(!strcmp(cmd,"push_back")){
            q2.push_back(a);
        }
        if(!strcmp(cmd, "push_front")) {
            q1.push_front(a);
        }
            
        if(!strcmp(cmd, "push_middle")) {
            q1.push_back(a);
        }

        if(q1.size() > q2.size()+1){
            q2.push_front(q1.back());
            q1.pop_back();
        }

        if(q2.size() > q1.size()){
            q1.push_back(q2.front());
            q2.pop_front();
        }
    } 
}

int main() {
    
    /* ios_base::sync_with_stdio(false);
    cin.tie(NULL); */

    solve();
    return 0;
}