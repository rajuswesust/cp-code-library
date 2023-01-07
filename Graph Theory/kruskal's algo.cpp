#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 1005;
vector<pair<int, ll>> adj[N];

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, u, v, w;
    cin >> n >> m;
    vector<pair<ll, pair<int, int>>> edges;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges.pb({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    dsu ds(n);
    ll totw = 0;    //total weight of the MST
    for(auto it: edges) {
        ll w = it.first;
        u = it.second.first;
        v = it.second.second;
        //cout << w << " " << u << " " << v << endl;
        if(ds.find_par(u) != ds.find_par(v)) {
            ds.union_by_size(u, v);
            totw += w;
        }
    }
    cout << totw << "\n";
    return 0;
}
/***

6 9
5 4 9
5 1 4
1 4 1
1 2 2
4 3 5
4 2 3
2 3 3
2 6 7
3 6 8
ans = 17
***/

