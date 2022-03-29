
#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define LOG 18

int a[N], table[N][LOG], _log[N];
int _log2(int n)
{
    int k=0;
    while(1<<(k+1) <= n)
        k++;
    return k;
}
void build_log()
{
    _log[1]=0;
    for(int i=2; i<N; i++)
        _log[i]=1+_log[i/2];
}
void build_table(int n)
{
    for(int j=1; j<LOG; j++)
    {
        for(int i=0; i+(1<<j)-1<n; i++)
        {
            int x=i+(1<<(j-1));
            table[i][j]=min(table[i][j-1], table[x][j-1]);
        }
    }
}

int Q(int L, int R, int n)
{
    int len=R-L+1;
    //int j=_log2(len);
    int j=_log[len];
    int x=R-(1<<j)+1;
    return min(table[L][j], table[x][j]);
}

void print(int n)
{
    int lim=_log2(n)+1;
    cout<<"printing("<<lim<<"): "<<endl;
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
    int n, q, l, r;
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        table[i][0]=a[i];
    }
    build_log();
    build_table(n);
    print(n);
    while(q--)
    {
        cin>>l>>r;
        cout<<Q(l-1, r-1, n)<<endl;
    }
    return 0;
}
/***

13 0
0 1 2 3 4 5 6 7 8 9 10 11 12

13 22
12 11 10 9 8 7 6 5 4 3 2 1 0
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
2 10
2 3
2 13
5 7
5 11
10 11
10 13
11 13
12 13
13 13
***/
