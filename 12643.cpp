#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int N, int a, int b) {
    int l, h, mean;

    if(b < a) {
        mean = a;
        a = b;
        b = mean;
    }

    l = 1;
    h = (1 << N);

    N++;
    while(N--) {
        mean = (l+h)/2;
        if(a <= mean && b > mean){
            cout << N << "\n";
            return;
        }
        if(b <= mean) {
            h = mean;
        }
        else {
            l = mean + 1;
        }
    }
}

int main() { 
    int N, a, b;
    while(scanf("%d %d %d", &N, &a, &b) != EOF) {
        solve(N, a, b);
    }
    return 0;
}

/*Solucao melhor
fazer a = (a+1)/2 e b = (b+1)/s
*/