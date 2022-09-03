#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5;
vector<int> g[N];
int dis[N], par[N], vis[N];
void bfs(int node) {
    queue<int> q;
    q.push(node), par[node] = -1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << "->";
        for(auto child: g[cur]) {
            if(!vis[child]) {
                q.push(child);
                dis[child] = dis[cur] + 1;
                par[child] = cur;
                vis[child] = 1;
            }
        }
    }
    return;
}
void dfs(int node, int p) {
    vis[node] = 1, par[node] = p;
    cout << node << "->";
    for(auto child: g[node]) {
        if(!vis[child]) {
            dfs(child, node);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, e, u, v;
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(int i = 1; i <= n; i++) {
        cout << i << ": " << par[i] << ", " << dis[i] << endl;
    }
    cout << endl;
    //memset(vis, 0, sizeof vis);
    //memset(par, 0, sizeof par);
    //dfs(1, -1);

    //printing shortest path
    v = 5;
    while(v != 1) {
        cout << v << "->";
        v = par[v];
    }
    return 0;
}
/***

5 7
1 2
1 3
2 3
2 4
3 4
3 5
4 5

***/
