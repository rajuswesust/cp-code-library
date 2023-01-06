#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pll pair<ll, ll>

const int N = 1e5 + 5;
const ll inf = LONG_LONG_MAX;
vector<pair<ll, ll>> g[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, u, v, c;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        //g[v].push_back({u, c});
    }
    //source = 1, destination = n
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});    //(cost, node)
    vector<ll> dis(n+1, inf);
    vector<int> prev(n+1);
    dis[1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        u = cur.se;
        //cout << "current working node:" << u << ", " << cur.fi << endl;
        if(u == n)
            break;
        if(dis[u] != cur.fi)
            continue;
        for(auto x: g[u]) {
            ll tmp = dis[u] + x.se;
            //cout << x.fi << " : " << tmp << endl;
            if(tmp < dis[x.fi]) {
                //cout << "relaxation" << endl;
                dis[x.fi] = tmp;
                prev[x.fi] = u;
                pq.push({tmp, x.fi});
            }
        }
    }
    //printing shortest distance from node 1
    for(int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;
    //printing previous node of a node in the shortest path
    for(int i = 1; i <= n; i++)
        cout << prev[i] << " ";
    cout << endl;
    
    if(dis[n] == INF) {
        cout << "-1\n";
        return 0;
    }
    v = prev[n];
    vector<int> path(1, n);
    while(v != 1) {
        path.push_back(v);
        v = prev[v];
    }
    path.push_back(1);
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << "\n";
    return 0;
}
/***

6 8
1 2 2
1 3 4
2 4 7
2 3 1
3 5 3
5 4 2
4 6 1
5 6 5

path: 1->2->3->5->4->6

***/
