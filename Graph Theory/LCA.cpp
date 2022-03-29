#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pb push_back
#define N 1005

const int mxx=11;
vector<int> adj[N];
int level[N], LCA[N][mxx];

int log2(int n)
{
    int res=0;
    while(n>0)
    {
        n>>=1;
        res++;
    }
    return res-1;
}

void dfs(int node, int par, int cur_lev)
{
    LCA[node][0]=par;
    level[node]=cur_lev;
    for(int child: adj[node])
    {
        if(child!=par)
        {
            dfs(child, node, cur_lev+1);
        }
    }
    return;
}

void init(int n)
{
    for(int i=0; i<mxx; i++)
        for(int j=0; j<N; j++)
            LCA[i][j]=-1;
    dfs(0, -1, 0);
    for(int j=1; j<mxx; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(LCA[i][j-1]!=-1)
            {
                int par=LCA[i][j-1];
                LCA[i][j]=LCA[par][j-1];
                //cout<<"#"<<i<<", "<<j<<", "<<par<<" "<<LCA[par][j-1]<<" "<<LCA[i][j]<<endl;
            }
        }
    }
    cout<<"----------------"<<endl;
    for(int i=0; i<n; i++)
        cout<<i<<": "<<level[i]<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<mxx; j++)
            cout<<LCA[i][j]<<" ";
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;

}

int lca(int a, int b)
{
    //we will assume that the level of b is deeper
    if(level[a]>level[b])
        swap(a, b);
    int diff=level[b]-level[a];
    while(diff>0)
    {
        int i=log2(diff);
        cout<<"i: "<<i<<endl;
        b=LCA[b][i];
        diff-=(1<<i);
    }
    cout<<"#current: "<<a<<" "<<b<<endl;
    if(a==b)
        return a;
    for(int i=mxx-1; i>=0; i--)
    {
        if(LCA[b][i]!=-1 && (LCA[b][i]!=LCA[a][i]))
            a=LCA[a][i], b=LCA[b][i];
    }
    return LCA[a][0];
}

int main()
{
    cout<<log2(32)<<" "<<log2(29)<<" "<<log2(1)<<" "<<log2(2)<<endl;
    int n, q, u, v;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init(n);

    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }
    return 0;
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
