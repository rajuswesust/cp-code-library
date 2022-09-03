#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 5;
ll a[N];
struct ST {
    #define lc (node << 1)
    #define rc (node << 1) + 1
    ll t[4 * N], lazy[4 * N];
    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void pull(int node) {
        t[node] = t[lc] + t[rc];    //change
    }
    inline void push(int node, int b, int e) {
        if(lazy[node] == 0)
            return;
        t[node] = t[node] + lazy[node] * (ll)(e-b+1);   //change
        if(b != e) {
            lazy[lc] = lazy[lc] + lazy[node];   //change
            lazy[rc] = lazy[rc] + lazy[node];   //change
        }
        lazy[node] = 0;
    }
    ll inline combine(ll a, ll b) {
        return a+b;                             //change
    }
    void build(int node, int b, int e) {
        lazy[node] = 0;
        if(b == e) {
            t[node] = a[b];
            return;
        }
        int mid = (b+e)>>1;
        build(lc, b, mid);
        build(rc, mid+1, e);
        pull(node);
    }
    void update(int node, int b, int e, int i, int j, ll x) {
        push(node, b, e);
        if(b > j || e < i)
            return;
        if(i <= b && e <= j) {
            lazy[node] = x;
            push(node, b, e);
            return;
        }
        int mid = (b+e) >> 1;
        update(lc, b, mid, i, j, x);
        update(rc, mid+1, e, i, j, x);
        pull(node);
    }
    ll query(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if(b > j || e < i) return 0;        //change
        if(i <= b && e <= j) return t[node];
        int mid = (b+e)>>1;
        return combine(query(lc, b, mid, i, j), query(rc, mid+1, e, i, j));
    }
     void print(int node, int b, int e) {
        cout << "[" << b << ", " << e << "] => " << t[node] << ", " << lazy[node] << endl;
        if(b == e)
            return;
        int mid = (b + e) >> 1;
        print(lc, b, mid);
        print(rc, mid+1, e);
    }

} t, tt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 7;
    for(int i=1; i<=n; i++)
        a[i] = i;

    t.build(1, 1, n);
    t.print(1, 1, n);

    t.update(1, 1, n, 2, 6, 3);
    t.print(1, 1, n);

    cout << t.query(1, 1, n, 4, 6) << endl;
    t.print(1, 1, n);

    cout << endl;
    tt.build(1, 1, n);
    tt.print(1, 1, n);

    tt.update(1, 1, n, 1, 5, 5);
    tt.print(1, 1, n);
    tt.update(1, 1, n, 3, 7, 2);
    tt.print(1, 1 , n);
    cout << tt.query(1, 1, n, 4, 5) << endl;
    tt.print(1, 1, n);
    return 0;
}

/***

#28 10 18 3 7 11 7 1 2 3 4 5 6 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

***/
