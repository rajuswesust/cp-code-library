#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 5;
int t[N * 4], a[N];
void build(int node, int b, int e) {
    if(b == e) {
        t[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    int lc = node << 1, rc = lc + 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    t[node] = t[lc] + t[rc];
}
int query(int node, int b, int e, int i, int j) {
    //cout << "#" << node << " "<< b <<" "<< e << " " << i << " " << j << endl;
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) {
        return t[node];
    }
    int mid = (b + e) >> 1;
    int lc = node << 1, rc = lc + 1;
    return query(lc, b, mid, i, j) + query(rc, mid+1, e, i, j);
}
void update(int node, int b, int e, int i, int x) {
    cout << "#]" << node << " "<< b <<" "<< e << " " << i << " " << x << endl;
    if(b > i || e < i) return;
    if(b == i && e == i) {
        t[node] = x;
        return;
    }
    int mid = (b + e) >> 1;
    int lc = node << 1, rc = lc + 1;
    update(lc, b, mid, i, x);
    update(rc, mid+1, e, i, x);
    t[node] = t[lc] + t[rc];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 7, q;
    //cin >> n;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    build(1, 1, n);
    for(int i=1; i<=4*n; i++)
        cout << t[i] << " ";
    cout << endl;

    cout << query(1, 1, n, 1, n) << endl;
    cout << query(1, 1, n, 2, n-1) << endl;
    cout << query(1, 1, n, n, n) << endl;
    cout << query(1, 1, n, 1, 1) << endl;
    cout << query(1, 1, n, 2, 6) << endl;

    update(1, 1, n, 3, -10);
    cout << query(1, 1, n, 1, n) << endl;
    cout << query(1, 1, n, 2, 6) << endl;

    return 0;
}

