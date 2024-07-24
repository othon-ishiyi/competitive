#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> w(1e5+1);

void mymerge(vector<int> &v, vector<int> &aux, int start, int m, int end, int &count) {
    int i = start, j = m+1, p = start;
    while(i <= m && j <= end) {
        if(w[v[i]] <= w[v[j]]) {
            aux[p++] = v[i++];
        }
        else{
            aux[p++] = v[j++];
            count += m-i+1;
        }
    }
    while(i <= m)
        aux[p++] = v[i++];
    while(j <= end)
        aux[p++] = v[j++];

    for(i = start; i <= end; i++)
        v[i] = aux[i];
}

void merge_sort(vector<int> &v, vector<int> &aux, int start, int end, int &count){
    if(start == end)
        return;

    int m = (start + end)/2;

    merge_sort(v, aux, start, m, count);
    merge_sort(v, aux, m+1, end, count);
    mymerge(v, aux, start, m, end, count);
}

int main() {
    int N, count = 0;
    cin >> N;
    vector<int> v, aux(N);

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        w[a] = i;
    }


    merge_sort(v, aux, 0, N-1, count);

    if(count&1)
        cout << "Impossible" << "\n";
    else
        cout << "Possible" << "\n";
    return 0;
}