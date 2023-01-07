#include <bits/stdc++.h>
using namespace std;

//use only union_by _rank or union_by_size
//do not use both in the same code
class dsu {
    vector<int> par, size, rank;
public:
    dsu(int n) {
        par.resize(n+1, 0);
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i = 1; i <= n; i++) {
            par[i] = i;
        }
    }
    int find_par(int u) {
        if(u == par[u])
            return u;
        return par[u] = find_par(par[u]);
    }
    void union_by_rank(int u, int v) {
        int pu = find_par(u), pv = find_par(v);
        if(pu == pv)
            return;
        if(rank[pu] < rank[pv])
            par[pu] = pv;
        else if(rank[pu] > rank[pv])
            par[pv] = pu;
        else {
            par[pv] = pu;
            rank[pu]++;
        }
    }
    void union_by_size(int u, int v) {
        int pu = find_par(u), pv = find_par(v);
        if(pu == pv)
            return;
        if(size[pu] < size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int main() {
    dsu ds(7);
    ds.union_by_size(1, 2);
    ds.union_by_size(2, 3);
    ds.union_by_size(4, 5);
    ds.union_by_size(6, 7);
    ds.union_by_size(5, 6);

    //checking if node 3 and 7 are in same cc
    if(ds.find_par(3) == ds.find_par(7))
        cout << "YES\n";
    else
        cout << "NO\n";
    ds.union_by_size(3, 7);
    if(ds.find_par(3) == ds.find_par(7))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
