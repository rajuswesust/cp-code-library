
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1005
#define pb push_back

vector<int> adj[N];
int par[N], level[N], n;

void dfs(int node, int p, int cur_lev)
{
    par[node]=p;
    level[node]=cur_lev;
    for(int child: adj[node])
    {
        if(child!=p)
        {
            dfs(child, node, cur_lev+1);
        }
    }
    return;
}
int lca(int a, int b)
{
    if(level[a]>level[b])
        swap(a, b);
    int diff=level[b]-level[a];
    while(diff>0)
    {
        b=par[b];
        diff--;
    }
    if(a==b)
        return a;
    while(par[a]!=par[b])
        a=par[a], b=par[b];
    return par[a];
}
int main()
{
    int u, v, q;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1, 0);
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }
}
/***

17
0 1
1 2
2 3
3 4
4 5
5 6
6 7
6 14
1 8
8 9
9 10
10 11
11 12
11 15
12 13
12 16

***/
