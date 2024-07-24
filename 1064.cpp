#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int N, int M) {
    vi stop(N), message(N, 0);
    vvi p(M, vi(3));
    vector<bool> visited(M, false);
    int buffer = 0, max_buffer = 0;
    for(int i=0; i<N; i++) {
        cin >> stop[i];
    }
    for(int i=0; i<M; i++) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        p[i][0]--;
    }

    for(int i=0; i<M; i++) {
        if(message[p[i][0]] + 1 == p[i][1]) {
            if(visited[i]) 
                buffer -= p[i][2] - p[i][1] + 1;
            message[p[i][0]] = p[i][2];
            visited[i] = true;
            i = 0;
        }
        else if(!visited[i]){
            visited[i] = true;
            buffer += p[i][2] - p[i][1] + 1;
            max_buffer = max(buffer, max_buffer);
        }
    }

    cout << max_buffer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, i=1;

    while(true) {
        cin >> N >> M;
        if(N == 0 and M == 0) break;
        cout << "Case " << i++ << ": ";
        solve(N, M);
    }
    return 0;
}