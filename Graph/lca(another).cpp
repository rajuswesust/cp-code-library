#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define N 105
#define LOG 7
#define pb push_back

int table[N][LOG], par[N], lev[N];
vector<int> adj[N];
void edge(int u, int v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}
int _log2(int n)
{
    int k=0;
    while(1<<(k+1) <= n)
        k++;
    return k;
}
void dfs(int node, int p)
{
    par[node]=p;
    for(int child: adj[node])
    {
        if(child != p)
        {
             lev[child]=lev[node]+1;
            dfs(child, node);
        }
    }
    return;
}
void build_table(int n)
{
    memset(table, -1, sizeof table);
    dfs(0, -1);

    for(int i=0; i<n; i++)
        table[i][0]=par[i];
    for(int j=1; j<LOG; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(table[i][j-1]!=-1)
            {
                int pos=table[i][j-1];
                table[i][j]=table[pos][j-1];
            }
        }
    }
}
int lca(int a, int b)
{
    if(lev[a]<lev[b])
        swap(a, b);

    int diff = lev[a]-lev[b], lim=_log2(lev[a])+1;
    while(diff>0)
    {
        int mxp=_log2(diff);
        a=table[a][mxp];
        diff -= (1<<mxp);
    }
    //cout<<"#"<<a<<", "<<b<<", "<<lim<<endl;
    if(a==b)
        return a;
    for(int j=lim; j>=0; j--)
    {
        if(table[a][j] != -1 && table[a][j]!=table[b][j])
            a=table[a][j], b=table[b][j];
    }
    return par[a];
}
void print(int n)
{
    int lim=_log2(n)+1;
    cout<<"printing table:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<lim; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n, q, u, v;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        edge(u, v);
    }
    /*
    for(int i=0; i<n; i++)
        cout<<par[i]<<" ";
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<lev[i]<<" ";
    cout<<endl;
    */
    build_table(n);
    //print(n);

    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }
    return 0;
}
/***

21
0 1
1 2
2 3
3 4
4 5
5 6
6 14
6 7
7 17
17 18
1 8
8 9
9 10
10 11
11 12
11 15
12 13
12 16
16 19
19 20

8
14 11
18 2
18 14
17 9
20 15
11 20
0 1
1 20

***/
