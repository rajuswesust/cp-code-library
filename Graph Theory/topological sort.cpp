#include <bits/stdc++.h>
using namespace std;

const int N = 205;

vector<vector<int>> adj;
int vis[N], indeg[N], out[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v, ok = 1;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        out[u]++;
        indeg[v]++;
    }
    vector<int> z, ans;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            z.push_back(i);
            vis[i] = 1;
        }
    }
    while(ans.size() < n) {
        if(z.empty()) {
            ok = 0;
            cout << "IMPOSSIBLE\n";
            break;
        }
        int cur = z.back();
        z.pop_back();
        ans.push_back(cur);
        for(int x: adj[cur])
        {
            indeg[x]--;
            if(!vis[x] && indeg[x] == 0) {
                z.push_back(x);
                vis[x] = 1;
            }
        }
        out[cur] = 0;
    }
    if(ok)
        for(auto it: ans) cout << it << " ";
    cout << "\n";
}
/***



***/


